#include "header/Json.h"
#include "header/JsonValue.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
using namespace std;


Json::Json() {
}
Json::~Json() {
}

string Json::str() {
    ostringstream oss;
    oss << "{" << endl;
    /*
    for_each(elements.begin(), elements.end(), [&] (auto & e) {
        oss << "\"" + e.first + "\": ";
        if (e.second->Type() == TYPE::VALUE) {
            oss << (static_pointer_cast<JsonValue>(e.second))->str() << endl;
        }
        else oss << e.second->str() << endl;
    });
    */
    oss << "}" << endl;
    return oss.str();
}
type_t Json::Type() {
    static type_t type = TYPE::JSONOBJ;
    return type;
}
Json & Json::add(const string key, JsonData && jsondata) {
    elements.insert(make_pair(key, make_shared<JsonData>(jsondata)));
    return * this;
}