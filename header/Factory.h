#pragma once

#include "Json.h"
#include "JsonData.h"
#include "JsonValue.h"
#include <memory>

class Factory {
public:
    static shared_ptr<JsonValue> newValue(const string value);
    static shared_ptr<JsonData> newJsonData();
    static shared_ptr<Json> newJson();
    
private:
};