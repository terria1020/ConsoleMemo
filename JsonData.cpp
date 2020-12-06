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
            oss << c->str();
            //TODO: TypeFilterCast 클래스를 만들어 공용으로 사용하게 할 것.
        });
    }
    return oss.str();
}

JsonData & JsonData::add(shared_ptr<JsonData> data) {
    child.push_back(data);
    return *this;
}
type_t JsonData::Type() {
    return 0;
}