nt convert_words_dat_file(const char *dict_file, const char *words_file)
{
	vector<string> words_vec;
	ifstream inf(dict_file, ios::in);
	string lab_text, lab_draw;
	while (inf >> lab_text >> lab_draw) {
		words_vec.push_back(lab_text);
	}

	char buf[128];
	FILE *pf = fopen(words_file, "wb");
	for (unsigned int i=0; i<words_vec.size(); i++){
		int len = words_vec[i].length();
		fwrite(&len, sizeof(int), 1, pf);
		fwrite(words_vec[i].c_str(), 1, len, pf);
	}
	return true;
}
