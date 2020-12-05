#pragma once
#include "JsonData.h"

class JsonValue : public JsonData {
protected:
    JsonValue();
    JsonValue(const string value);

public:
    ~JsonValue();
    string str() override;
    type_t Type() override;

private:
    struct JsonValueFactory {
        JsonValueFactory() {}
        static shared_ptr<JsonValue> newValue(const string value) {
            return make_shared<JsonValue> (JsonValue{value});
        }
    };

    string value;
public:
    typedef JsonValueFactory Factory;
};

