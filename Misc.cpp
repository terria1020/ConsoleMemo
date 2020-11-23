#include "header/Misc.h"
#include <sstream>

string operator*(const string & s, int n) {
    stringstream sstream;
    for(int i = 0; i < n; i++) {
        sstream << s;
    }
    return sstream.str();
}
string operator*(int n, const string & s) {
    return operator*(s, n);
}

string blank(const int level) {
    static stringstream space;
    space << " ";
    return space.str() * level;
}