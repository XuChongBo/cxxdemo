#include <stdio.h>
#include <iostream>
#include <fstream>
#include "opencv2/opencv.hpp"
//#include "../include/ocr_interface.h"
#include <Magick++.h> 
#include "utils.h"

using namespace std;

leveldb::DB* g_db=NULL;
std::string g_image_key = "";



void save_line_result_to_leveldb(cv::Mat &cv_img, vector<RecogLine> &lines,double scale)
{

    std::string value;
    dataset::BlockList blocklist;
    int count=0;
	for(unsigned int i = 0; i<lines.size(); i++) {

		//cv::putText(doc_result->debug_img, buf, Point(rc.x2, rc.y1 + 10), CV_FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255));
		int len = (int)lines[i].line.size();
		for(int j=0; j<len; j++) {
			RecogRect  reg_rect = lines[i].line[j];



			//world rect
			std::string word = reg_rect.word;
			float weight = reg_rect.score;

			dataset::Block* ptrBlock = blocklist.add_blocks();
			ptrBlock->set_x1(reg_rect.x1()/scale);
			ptrBlock->set_y1(reg_rect.y1()/scale);
			ptrBlock->set_x2(reg_rect.x2()/scale);
			ptrBlock->set_y2(reg_rect.y2()/scale);
			ptrBlock->set_text(word);

            dataset::ImageEntity crop;
            crop.set_channels(1);
            crop.set_height(reg_rect.y2()-reg_rect.y1());
            crop.set_width(reg_rect.x2()-reg_rect.x1());
            crop.set_recog_text(word);
           // std::cout<<"word="<<word<<endl;
            crop.set_score(weight);
            string* data_string = crop.mutable_data();
            unsigned char *ptr = cv_img.data; 

            for (int y=reg_rect.y1(); y<reg_rect.y2(); ++y)
            {
                for (int x=reg_rect.x1(); x<reg_rect.x2(); ++x)
                {
                    data_string->push_back(*(ptr+y*cv_img.cols+x));    
                }
            }
           /*
            std::cout<<data_string->length()<<" "<<reg_rect.width()<<" " <<reg_rect.height()<<endl;

            cv::Mat a;
            cv::Rect cv_rect(reg_rect.x1(),reg_rect.y1(),reg_rect.x2()-reg_rect.x1(), reg_rect.y2()-reg_rect.y1());

 
            cv_img(cv_rect).copyTo(a);
            my_imshow("img",cv_img);
            cv::waitKey(-1);            
            my_imshow("x",a);
            cv::waitKey(-1);
            int x;
            std::cin >>x;
            */
            //put to leveldb
            std::stringstream ss;
            ss<<count++;        
            std::string cropkey = "crop"+g_image_key.substr(g_image_key.find('~'))+"~"+ss.str();

            crop.SerializeToString(&value);
            leveldb::Status status = g_db->Put(leveldb::WriteOptions(), cropkey, value);
            assert(status.ok());
          //  std::cout<<"Put cropkey="<<cropkey<<endl;
				
		}

	}

	blocklist.SerializeToString(&value);

	// 添加key=value
    std::string key = "cn_blocks"+g_image_key.substr(g_image_key.find('~'));
    leveldb::Status status = g_db->Put(leveldb::WriteOptions(), key, value);
    assert(status.ok());

	std::cout<<"the key="<<key<< endl
		<<"blocklist size="<<blocklist.blocks_size()<<endl;
}

void save_line_result_to_leveldb(vector<EnLine> &lines,double scale)
{

    dataset::BlockList blocklist;

    for(unsigned int i = 0; i<lines.size(); i++) {

        //cv::putText(doc_result->debug_img, buf, Point(rc.x2, rc.y1 + 10), CV_FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255));
        int len = (int)lines[i].rects.size();
        for(int j=0; j<len; j++) {
            RecogRect  reg_rect = lines[i].rects[j];


            // MyRect rc = reg_rect.rc;   
            //world rect
            std::string word = reg_rect.word;

            dataset::Block* ptrBlock = blocklist.add_blocks();

            
            ptrBlock->set_x1(reg_rect.x1()/scale);
            ptrBlock->set_y1(reg_rect.y1()/scale);
            ptrBlock->set_x2(reg_rect.x2()/scale);
            ptrBlock->set_y2(reg_rect.y2()/scale);

            ptrBlock->set_text(word);

                    
        }

    }

    std::string value;

    blocklist.SerializeToString(&value);
    std::string key = "en_blocks"+g_image_key.substr(g_image_key.find('~'));
    // 添加key=value
    leveldb::Status status = g_db->Put(leveldb::WriteOptions(), key, value);
    assert(status.ok());


    std::cout<<"the key="<<key<< endl
        <<"blocklist size="<<blocklist.blocks_size()<<endl;
}


void save_result_to_leveldb(std::string &result, std::string prefix)
//prefix =  "cn_result" or "en_result" or "cnen_result"
{

    std::string key = prefix+g_image_key.substr(g_image_key.find('~'));
    // 添加key=value
    if(result==""){
        result = "None";
        cout<<"None"<<endl;
    }
    leveldb::Status status = g_db->Put(leveldb::WriteOptions(), key, result);
    assert(status.ok());
    std::cout<<"Put the key="<<key<<endl;
}


void save_timecost_to_leveldb(int cost_ms, std::string prefix)
//prefix =  "en_cost" or "cn_cost" 
{

    std::stringstream ss;
    ss<<cost_ms;
    std::string tt;
    ss>>tt;

    std::string key = prefix+g_image_key.substr(g_image_key.find('~'));
    // 添加key=value
    leveldb::Status status = g_db->Put(leveldb::WriteOptions(), key, tt);
    assert(status.ok());
    std::cout<<"Put the key="<<key<<endl;
}




void save_result_type_to_leveldb(int t)
{

    // std::string result_type_str = "null";
    // if(t==twocr_language_cn){
    //     result_type_str="cn";
    // }else if(t==twocr_language_en){
    //     result_type_str="en";
    // }
    // std::string key = "result_type"+g_image_key.substr(g_image_key.find('~'));
    // // 添加key=value
    // leveldb::Status status = g_db->Put(leveldb::WriteOptions(), key, result_type_str);
    // assert(status.ok());
    // std::cout<<"Put the key="<<key<<endl;
}


void save_image_to_leveldb(std::string prefix, cv::Mat &cv_img) 
{

  assert(cv_img.data);
  dataset::ImageEntity image_entity;
  int nChannels = cv_img.channels();
  image_entity.set_channels(nChannels);
  image_entity.set_height(cv_img.rows);
  image_entity.set_width(cv_img.cols);
  image_entity.clear_data();

  string* data_string = image_entity.mutable_data();
    for (int i = 0; i < cv_img.rows*cv_img.cols; i++)
    {
        unsigned char *ptr = cv_img.data + i*nChannels;
        for (int c = 0; c < nChannels; ++c) {
            data_string->push_back(*(ptr+c));
        }
    }

    g_db->Put(leveldb::WriteOptions(), prefix+"~~", "111");

    string value;
    // get the value
    image_entity.SerializeToString(&value);
    std::string key = prefix+g_image_key.substr(g_image_key.find('~'));
    // 添加key=value
    leveldb::Status status = g_db->Put(leveldb::WriteOptions(), key, value);
    assert(status.ok());
    std::cout<<"Put the key="<<key<<endl;

}


void save_enline_crops_to_leveldb(vector<EnLine> &lines, vector<IplImage *> line_imgs)
{

    std::string value;
    int count=0;
    for (int k = 0; k < line_imgs.size(); k++) {
            cv::Mat tmp = line_imgs[k];
            cv::Mat mat;
            cv::transpose(tmp, mat);
            dataset::ImageEntity crop;
            crop.set_channels(1);
            crop.set_height(mat.rows);
            crop.set_width(mat.cols);
            crop.set_recog_text(lines[k].str);
           // std::cout<<"word="<<word<<endl;
            //crop.set_score(weight);
            string* data_string = crop.mutable_data();
            unsigned char *ptr = mat.data; 
            for (int i = 0; i < mat.rows*mat.cols; i++)
            {
                data_string->push_back(*(ptr++));  
            }

            std::stringstream ss;
            ss<<count++;        
            std::string cropkey = "enline_crop"+g_image_key.substr(g_image_key.find('~'))+"~"+ss.str();

            crop.SerializeToString(&value);
            leveldb::Status status = g_db->Put(leveldb::WriteOptions(), cropkey, value);
            assert(status.ok());

    }
}







void doc_draw_every_rect(vector<cv::Rect> &rects, Mat &rects_img, int chhei)
{
    for (unsigned int i=0; i<rects.size(); i++) {
        if (rects[i].width <= 0) continue;
        cv::rectangle(rects_img, rects[i], cv::Scalar(255));
    }
    cv::rectangle(rects_img, cv::Rect(0,0,chhei,chhei), cv::Scalar(255));
}


void doc_draw_every_rect(std::map<std::string, RecogRect>  &rects, Mat &rects_img, int chhei)
{
    std::map<std::string, RecogRect>::iterator itr;
    for (itr=rects.begin(); itr!=rects.end(); itr++) {
        RecogRect rrc = itr->second;
        cv::Rect r(rrc.x1(), rrc.y1(), rrc.x2() - rrc.x1(), rrc.y2() - rrc.y1());
        cv::rectangle(rects_img, r, cv::Scalar(255));

        cout<<"("<<rrc.x1()<<"," << rrc.y1()<<"," << rrc.x2()<<","<<rrc.y2()<<") key="<<itr->first<<endl;
    }

    cv::Rect rc(0, 0, chhei, chhei);
    cv::rectangle(rects_img, rc, cv::Scalar(255),2);

    stringstream ss;
    ss <<"total: "<< rects.size();

    cv::putText(rects_img, ss.str(),  cv::Point(10,10), CV_FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255));
}


void doc_draw_every_rect(vector<RecogRect> &rects, Mat &rects_img, int chhei)
{
    if (rects_img.type()==CV_8UC1) {
        cvtColor(rects_img,rects_img,CV_GRAY2RGB);
    }


    for (unsigned int i=0; i<rects.size(); i++) {
        //cv::Rect rc(rects[i].x1, rects[i].y1, rects[i].x2 - rects[i].x1, rects[i].y2 - rects[i].y1);
        cv::rectangle(rects_img, rects[i].rc, cv::Scalar(255,0,0));
    }

    cv::Rect rc(0, 0, chhei, chhei);
    cv::rectangle(rects_img, rc, cv::Scalar(0,0,0),2);
}

void doc_draw_combine_rect(vector<RecogRect> &rects, Mat &rects_img, int chhei)
{
    if (rects_img.type()==CV_8UC1) {
        cvtColor(rects_img,rects_img,CV_GRAY2RGB);
    }

    for (unsigned int i=0; i<rects.size(); i++) {
        cv::Rect rc(rects[i].x1(), rects[i].y1(), rects[i].x2() - rects[i].x1(), rects[i].y2() - rects[i].y1());
        int c = 255;
        cv::Scalar color = cv::Scalar(255,0,0);     
        if(rects[i].ncc==2) {
            color = cv::Scalar(0,255,0);
        }else if (rects[i].ncc==3) {
            color = cv::Scalar(0,0,255);
        }else if (rects[i].ncc==4) {
            color = cv::Scalar(255,255,255);
        }

        cv::rectangle(rects_img, rc, color);
    }

    cv::Rect rc(0, 0, chhei, chhei);
    cv::rectangle(rects_img, rc, cv::Scalar(0),2);
}

void draw_word(Magick::Image  &image, int left, int bottom, string txt){
        ////////////////////////draw text  ///////////////////
    //construct a drawing list
    std::list<Magick::Drawable> drawList;
    drawList.push_back(Magick::DrawableStrokeWidth(1)); 
    drawList.push_back(Magick::DrawablePointSize(20));
    // set the text font: the font is specified via a string representing 
    // a fully qualified X font name (wildcards '*' are allowed).   identify -list font | more.  get the Font Name
    //drawList.push_back(DrawableFont("WenQuanYi-Zen-Hei-Mono-Regular"));
    drawList.push_back(Magick::DrawableFont("WenQuanYi-Zen-Hei-Regular"));
   // drawList.push_back(DrawableStrokeColor(police_color)); 
    drawList.push_back(Magick::DrawableStrokeColor("black")); // Outline Color   //Color("black")
    // set the text to be drawn at specified position: x=101, y=50 this case
    drawList.push_back(Magick::DrawableText(left,bottom,txt));
    //drawList.push_back(DrawableText(100,70,"dist ∞  α Σ  ∈  □  √  ance"));

    image.draw(drawList);
}
//(x,y) is the left bottom of the txt rectangle
void draw_text(Mat &img, vector<RecogRect> &rects, std::map<string, string> &sym_out_map)
{


    if (img.type()==CV_8UC1) {
        cvtColor(img,img,CV_GRAY2RGB);
    }

    int w = img.cols;
    int h = img.rows;
    unsigned char *ptr = img.data;
  //   Magick::Image image(Magick::Geometry(w, h),"white");     //Image blank_image( Geometry(640, 480), Color(MaxRGB, MaxRGB, MaxRGB, 0));
  //   for(int y=0; y<h; y++) {
     //    for( int x=0; x<w; x++) {
     //          Magick::Color color(*ptr,*(ptr+1),*(ptr+2));
     //          image.pixelColor(x,y,color); 
     //          ptr+=3;
  //    }
    // } 
    Magick::Image image(w,h,"BGR", Magick::CharPixel, (char *)img.data);

    for (int i=0; i<(int)rects.size(); i++) {
        int left = rects[i].x1();
        int bottom = rects[i].y1();
        if (rects[i].y1()<20){
            bottom=rects[i].y2();
        }
        string word = rects[i].word;
        if (sym_out_map.count(word)>0) {
            word = sym_out_map[word];
        }
        draw_word(image,left,bottom,word);
    }

    image.write(0,0,w,h,"BGR", Magick::CharPixel, (char *)img.data);

    ////////////////////////copy back ///////////////////
  //   ptr = img.data;
  //   for(int y=0; y<h; y++) {
     //    for( int x=0; x<w; x++) {
     //          Magick::Color pc=image.pixelColor(x,y); 
        //       *ptr++ = pc.redQuantum();
  //              *ptr++ = pc.greenQuantum();
  //              *ptr++ = pc.blueQuantum();
  //    }
    // } 

}

//(x,y) is the left bottom of the txt rectangle
void draw_text(Mat &img, vector<TermRect> &rects)
{
    


    if (img.type()==CV_8UC1) {
        cvtColor(img,img,CV_GRAY2RGB);
    }

    int w = img.cols;
    int h = img.rows;
    unsigned char *ptr = img.data;
  //   Magick::Image image(Magick::Geometry(w, h),"white");     //Image blank_image( Geometry(640, 480), Color(MaxRGB, MaxRGB, MaxRGB, 0));
  //   for(int y=0; y<h; y++) {
     //    for( int x=0; x<w; x++) {
     //          Magick::Color color(*ptr,*(ptr+1),*(ptr+2));
     //          image.pixelColor(x,y,color); 
     //          ptr+=3;
  //    }
    // } 
    Magick::Image image(w,h,"BGR", Magick::CharPixel, (char *)img.data);
    for (int i=0; i<(int)rects.size(); i++) {
        if(rects[i].info=="invalid"){
            continue;
        }
        int left = rects[i].x1();
        int bottom = rects[i].y1();
        if (rects[i].y1()<10){
            bottom=rects[i].y2();
        }
        string word = rects[i].word;
        // if (sym_out_map.count(word)>0) {
        //  word = sym_out_map[word];
        // }
        draw_word(image,left,bottom,word);
    }

    image.write(0,0,w,h,"BGR", Magick::CharPixel, (char *)img.data);
  //   ////////////////////////copy back ///////////////////
  //   ptr = img.data;
  //   for(int y=0; y<h; y++) {
     //    for( int x=0; x<w; x++) {
     //          Magick::Color pc=image.pixelColor(x,y); 
        //       *ptr++ = pc.redQuantum();
  //              *ptr++ = pc.greenQuantum();
  //              *ptr++ = pc.blueQuantum();
  //    }
    // } 

}


void doc_draw_recog_rects(vector<RecogRect> &rects, Mat &rects_img, int chhei)
{
    if (rects_img.type()==CV_8UC1) {
        cvtColor(rects_img,rects_img,CV_GRAY2RGB);
    }

    for (unsigned int i=0; i<rects.size(); i++) {
        cv::Rect rc(rects[i].x1(), rects[i].y1(), rects[i].x2() - rects[i].x1(), rects[i].y2() - rects[i].y1());
        int c = 255;
        cv::Scalar color = get_color(rects[i].word); // cv::Scalar(255,255,255);    
        cv::rectangle(rects_img, rc, color);

        //cv::putText(rects_img, rects[i].word, Point(rc.x, rc.y ), CV_FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255,255,255));


    }

    cv::Rect rc(0, 0, chhei, chhei);
    cv::rectangle(rects_img, rc, cv::Scalar(0),2);
}

// void show_rect_img(cv::Mat &gray_img, RecogRect &rrc)
// {   
//     Mat char_img;
//     gray_img(rrc.rc).copyTo(char_img);

//     my_imshow("char_img", char_img);
//     //cv::waitKey(0);
// }

void my_imshow(std::string name, cv::Mat &img, bool isBlock)
{
    cout<<"wait to draw "<<name<<" "<< isBlock <<std::endl;
    #pragma omp critical 
    {
        cout<<"doing draw "<<name<<" "<< isBlock <<std::endl;
        cv::imshow(name, img);
        if(isBlock){
            cv::waitKey(-1);
        }
        cout<<"to draw "<<name <<" ok"<<std::endl;
    }
}

cv::Scalar get_color(string word) 
{   
    if (word.length()<=0) {
        return cv::Scalar(255,255,255);
    }else if(is_letter(word)){
        return cv::Scalar(30,150,250);
    }else if(is_hanzi(word)){
        return cv::Scalar(255,0,0);
    }else{
        return cv::Scalar(0,255,255);
        
    }
}

void doc_draw_every_line(vector<RecogLine> &lines, Mat &rects_img, int chhei)
{
    if (rects_img.type()==CV_8UC1)
    {
        cvtColor(rects_img,rects_img,CV_GRAY2RGB);
    }
    

    char buf[100];
    for (unsigned int i=0; i<lines.size(); i++) {
        vector<RecogRect> line = lines[i].line;
        if (line.size() < 1) continue;
        sprintf(buf, "%d", i+1);
        cv::putText(rects_img, buf, Point(line[0].x1(), line[0].y1() ), CV_FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255,255,255));

        cv::Point pt1, pt2;
        pt1.x = (line[0].x1() + line[0].x2()) / 2;
        pt1.y = (line[0].y1() + line[0].y2()) / 2;
        cv::Rect rci(line[0].x1(), line[0].y1(), line[0].x2() - line[0].x1(), line[0].y2() - line[0].y1());

        cv::rectangle(rects_img, rci, get_color(line[0].word));
        //if (line[0].info == "dot") cv::rectangle(rects_img, rci, cv::Scalar(0), 1);

        
        for(unsigned int j=1; j<line.size(); j++) {
            pt2.x = (line[j].x1() + line[j].x2()) / 2;
            pt2.y = (line[j].y1() + line[j].y2()) / 2;
            cv::Rect rcj(line[j].x1(), line[j].y1(), line[j].x2() - line[j].x1(), line[j].y2() - line[j].y1());
            cv::rectangle(rects_img, rcj, get_color(line[j].word));
            //if (line[j].info == "dot") cv::rectangle(rects_img, rcj, cv::Scalar(0), 1);


            cv::line(rects_img, pt1, pt2, cv::Scalar(255,255,255), 1);
            pt1 = pt2;
        }
        //sprintf(buf, "%.2g", lines[i].score);
        //cv::putText(rects_img, buf, Point(line[line.size() - 1].x2(), line[line.size() - 1].y1() + 10), CV_FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255));
    }
    cv::Rect rci(0, 0, chhei, chhei);
    cv::rectangle(rects_img, rci, cv::Scalar(0,255,0));
}

void doc_draw_term_lines(vector<TermLine> &lines, Mat &rects_img, int chhei)
{
    if (rects_img.type()==CV_8UC1)
    {
        cvtColor(rects_img,rects_img,CV_GRAY2RGB);
    }
    

    char buf[100];
    for (unsigned int i=0; i<lines.size(); i++) {
        vector<TermRect> rects = lines[i].rects;
        if (rects.size() < 1) continue;
        sprintf(buf, "%d", i+1);
        cv::putText(rects_img, buf, Point(rects[0].x1(), rects[0].y2() ), CV_FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255,255,255));

        cv::Point pt1, pt2;
        pt1.x = (rects[0].x1() + rects[0].x2()) / 2;
        pt1.y = (rects[0].y1() + rects[0].y2()) / 2;
        cv::Rect rci(rects[0].x1(), rects[0].y1(), rects[0].x2() - rects[0].x1(), rects[0].y2() - rects[0].y1());

        cv::rectangle(rects_img, rci, get_color(rects[0].word));
        //if (rects[0].info == "dot") cv::rectangle(rects_img, rci, cv::Scalar(0), 1);

        
        for(unsigned int j=1; j<rects.size(); j++) {
            pt2.x = (rects[j].x1() + rects[j].x2()) / 2;
            pt2.y = (rects[j].y1() + rects[j].y2()) / 2;
            cv::Rect rcj(rects[j].x1(), rects[j].y1(), rects[j].x2() - rects[j].x1(), rects[j].y2() - rects[j].y1());
            cv::rectangle(rects_img, rcj, get_color(rects[j].word));
            //if (rects[j].info == "dot") cv::rectangle(rects_img, rcj, cv::Scalar(0), 1);


            cv::line(rects_img, pt1, pt2, cv::Scalar(255,255,255), 1);
            pt1 = pt2;
        }
        //sprintf(buf, "%.2g", lines[i].score);
        //cv::putText(rects_img, buf, Point(line[line.size() - 1].x2(), line[line.size() - 1].y1() + 10), CV_FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255));
    }
    cv::Rect rci(0, 0, chhei, chhei);
    cv::rectangle(rects_img, rci, cv::Scalar(0,255,0));
}


// void average_area_term_lines(vector<TermLine> &lines, Mat &in_img, cv::Mat &out_img)
// {
//     if(in_img.type()==CV_8UC1){
//         cout<<"in_img type error. in average_area_term_lines"
//         return ;
//     }
//     cv::Scalar m = cv::mean(in_img);

// }
