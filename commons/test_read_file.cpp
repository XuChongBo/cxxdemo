#include <map>
#include <vector> 
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

std::vector<std::string> get_lines(std::string file_path)
{
    vector<string> lines;
    //ifstream fin("a.txt");  
    ifstream fin(file_path.c_str());  
    string s;  
    while( getline(fin,s) ) {    
    //cout << "Read from file: " << s << endl; 
        lines.push_back(s);
    }
    return lines;
}

void iterate_work(std::vector<std::string> &lines)
{
    for(int i=0;  i<lines.size(); i++){
        std::cout<<lines[i]<<std::endl;
    }
}


int main(int argc, char *argv[])
{
    vector<string> lines =  get_lines(string(argv[1]));
    iterate_work(lines);
    /*
		vector<string> char_index_;
			FILE *pf = fopen(dict_file.c_str(), "rb");
		if (pf == NULL) return false;
		int len = 0;
		char buf[128];
		while (fread(&len, sizeof(int), 1, pf) > 0) {
			fread(buf, 1, len, pf);
			buf[len] = 0;
			string lab_text = buf;
			char_index_.push_back(lab_text);
		}
    */
}
