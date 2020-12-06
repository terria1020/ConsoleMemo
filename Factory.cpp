#include "header/Factory.h"

shared_ptr<JsonValue> Factory::newValue(const string value) {
    return make_shared<JsonValue> (JsonValue{});
}
shared_ptr<JsonData> Factory::newJsonData() {
    return make_shared<JsonData> (JsonData{});
}
shared_ptr<Json> Factory::newJson() {
    return make_shared<Json> (Json{});
}
