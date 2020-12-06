#include "header/JsonData.h"
#include <algorithm>
#include <sstream>

using namespace std;

JsonData::JsonData() {
}
JsonData::~JsonData() {
}

string JsonData::str() {
    ostringstream oss;
    if (child.size() > 0) {
        for_each(child.begin(), child.end(), [&] (auto & c) {
            oss << c.str();
        });
    }
    return oss.str();
}
type_t JsonData::Type() {
    return 0;
}