#pragma once
#include <string>
using std::string;

#define COLOR(T, TYPE) ColorString::getColor(T, TYPE)

enum COLORTYPE {
    MEMO,
    TAG,
    ERROR
};

class ColorString {
public:
    static string getColor(const string text, COLORTYPE type);

private:
    static string flag;
    static string e_flag;
    static string MEMOCOLOR;
    static string MEMOBG;
    static string TAGCOLOR;
    static string TAGBG;
    static string ERRORCOLOR;
};
