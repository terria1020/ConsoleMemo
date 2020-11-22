#pragma once
#include "JsonData.h"

class JsonValue : public JsonData {
public:
    JsonValue();
    JsonValue(const string value);
    ~JsonValue();

    string str() override;
    type_t Type() override;
private:
    string value;
};