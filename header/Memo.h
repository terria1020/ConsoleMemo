#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Memo {
	string name;
	vector<string> tag;

	int tagindex;

	Memo(const string name);
	~Memo();
};