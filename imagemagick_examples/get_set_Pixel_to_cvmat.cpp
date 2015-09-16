

unsigned char *ptr = img.data;
Magick::Image image(Magick::Geometry(w, h),"white");		//Image blank_image( Geometry(640, 480), Color(MaxRGB, MaxRGB, MaxRGB, 0));


/////////////////////// set ///////////////////
for(int y=0; y<h; y++) {
	    for( int x=0; x<w; x++) {
	          Magick::Color color(*ptr,*(ptr+1),*(ptr+2));
	          image.pixelColor(x,y,color); 
	          ptr+=3;
  }
} 



/////////////////////// get ///////////////////
    ptr = img.data;
  for(int y=0; y<h; y++) {
	    for( int x=0; x<w; x++) {
	          Magick::Color pc=image.pixelColor(x,y); 
		      *ptr++ = pc.redQuantum();
  		      *ptr++ = pc.greenQuantum();
  		      *ptr++ = pc.blueQuantum();
    	}
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
  //   Magick::Image image(Magick::Geometry(w, h),"white");   //Image blank_image( Geometry(640, 480), Color(MaxRGB, MaxRGB, MaxRGB, 0));
  //   for(int y=0; y<h; y++) {
   //    for( int x=0; x<w; x++) {
   //          Magick::Color color(*ptr,*(ptr+1),*(ptr+2));
   //          image.pixelColor(x,y,color); 
   //          ptr+=3;
  //    }
  // } 
  Magick::Image image(w,h,"BGR", Magick::CharPixel, (char *)img.data);

  for (int i=0; i<(int)rects.size(); i++) {
    int left = rects[i].rc.x1;
    int bottom = rects[i].rc.y1;
    if (rects[i].rc.y1<10){
      bottom=rects[i].rc.y2;
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
  //          *ptr++ = pc.greenQuantum();
  //          *ptr++ = pc.blueQuantum();
  //    }
  // } 

}