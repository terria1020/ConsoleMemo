#include "header/Json.h"
#include "header/JsonValue.h"
#include <algorithm>
#include <iostream>
using namespace std;


Json::Json() {
}
Json::~Json() {
}

string Json::str() {
    return "\"" + key + "\": ";
}
type_t Json::Type() {
    static type_t type = TYPE::JSONOBJ;
    return type;
}

Json & Json::addKey(const string key) {
    this->key = key;
    return *this;
}
Json & Json::addValue(const string value) {
    data.push_back(make_shared<JsonValue>(JsonValue{value}));
    return *this;
}
Json & Json::addJson(Json & json) {
    data.push_back(make_shared<Json>(json));
    return *this;
}

JsonData & Json::operator[] (const int index) const {
    //if (index < 0 || index >= data.size()) throw("invalid index.")
    return *data[index];
}