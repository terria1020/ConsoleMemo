#pragma once
#include "JsonData.h"
#include "Interfaces.h"
#include <vector>
#include <memory>

using namespace std;

class Json : public JsonData {
public:
    Json();
    ~Json();

    string str() override;
    type_t Type() override;

    Json & addKey(const string key);
    Json & addValue(const string value);
    Json & addJson(Json & json);

    JsonData & operator[] (const int index) const;

    friend class JsonManager;
    friend class JsonConsoleLogger;
    friend class JsonMaker;
    friend class JsonParser;
private:
    string key;
    vector<shared_ptr<JsonData>> data;
};