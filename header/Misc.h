#pragma once
#include <string>
#include <sstream>

using namespace std;

string operator*(const string & s, int n);
string operator*(int n, const string & s);

string blank(const int level);
