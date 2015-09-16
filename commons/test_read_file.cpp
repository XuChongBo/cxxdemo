#include <map>
#include <vector> 
#include <iostream>

using namespace std;

int main()
{
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

}
