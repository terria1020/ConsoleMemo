#include "header/Json.h"
#include "header/JsonValue.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;


Json::Json() {
}
Json::~Json() {
}

string Json::str() {
    ostringstream oss;
    oss << "{" << endl;
    if (key != "") oss << "\"" + key + "\": ";
    int temp = 0;
    int size = data.size();
    for_each(data.begin(), data.end(), [&oss, &temp, size] (shared_ptr<JsonData> jsondata) {
        //oss << data->str() << endl;
        if (jsondata->Type() == TYPE::VALUE) oss << jsondata->str() << endl;
        else oss << jsondata->str();
    });
    oss << "}" << endl;
    return oss.str();
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

JsonData & Json::operator[] (const int index) const throw(int) {
    if (index < 1 || index >= data.size()) throw(-1);
    return *data[index];
}