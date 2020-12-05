#pragma once
#include "JsonData.h"
#include "Interfaces.h"
#include <vector>
#include <memory>
#include <map>

using namespace std;

class Json : public JsonData {
protected:
    Json();

public:
    ~Json();
    string str() override;
    type_t Type() override;

    Json & add(const string key, shared_ptr<JsonData> data);

    friend class JsonManager;
    friend class JsonConsoleLogger;
    friend class JsonMaker;
    friend class JsonParser;

private:
    struct JsonFactory {
        JsonFactory() {}
        static shared_ptr<Json> newJson() {
            return make_shared<Json> (Json{});
        }  
    };
    map<string, JsonData_PTR> elements;

public:
    typedef JsonFactory Factory;
};

