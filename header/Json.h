#pragma once
#include "JsonData.h"
#include "Interfaces.h"
#include <vector>
#include <memory>
#include <map>

using namespace std;

class Json : public JsonData {
public:
    Json();
    ~Json();

    string str() override;
    type_t Type() override;

    Json & add(const string key, JsonData && jsondata);

    friend class JsonManager;
    friend class JsonConsoleLogger;
    friend class JsonMaker;
    friend class JsonParser;
public:
    map<string, JsonData_PTR> elements;
};