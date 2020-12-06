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
    
    for_each(elements.begin(), elements.end(), [&] (auto & e) {
        
        //pair->first = key
        oss << "\"" + e.first + "\": ";

        //pair->second = value
        if (e.second->Type() == TYPE::VALUE) {
            //TODO: TypeFilterCast 클래스를 만들어 공용으로 사용하게 할 것.
            //auto sub = static_pointer_cast<JsonValue> (e.second);
            oss << (static_pointer_cast<JsonValue>(e.second))->str() << endl;
            //oss << sub->str() << endl;
        }
        else oss << e.second->str() << endl;
    });
    
    oss << "}";
    return oss.str();
}
type_t Json::Type() {
    static type_t type = TYPE::JSONOBJ;
    return type;
}
Json & Json::add(const string key, shared_ptr<JsonData> data) {
    //if (jsondata.Type() == TYPE::VALUE) elements.insert(make_pair(key, make_shared<JsonData>(dynamic_cast<JsonValue>(jsondata))));
    elements.push_back(make_pair(key, data));
    return * this;
}