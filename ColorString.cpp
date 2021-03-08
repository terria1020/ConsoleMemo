#ifdef _WIN32
    #include "header\ColorString.h"
#else
    #include "header/ColorString.h"
#endif


string ColorString::getColor(const string text, COLORTYPE type) {
    string color;
    string bg;
    
    if (type == COLORTYPE::MEMO) {
        color = MEMOCOLOR;
        bg = MEMOBG;
    }
    else if (type == COLORTYPE::TAG) {
        color = TAGCOLOR;
        bg = TAGBG;
    }
    else if (type == COLORTYPE::ERROR) {
        color = ERRORCOLOR;
        return flag + color + text + e_flag;
    }
    return flag + color + flag + bg + text + " " + e_flag;
}

string ColorString::flag = "\x1b[";
string ColorString::e_flag = "\x1b[0m";
string ColorString::MEMOCOLOR = "92m";
string ColorString::MEMOBG = "103m";
string ColorString::TAGCOLOR = "94m";
string ColorString::TAGBG = "35m";
string ColorString::ERRORCOLOR = "31m";