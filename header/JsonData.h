#pragma once
#include "Interfaces.h"
#include <memory>
#include <vector>

using namespace std;

class JsonData : public IJsonData {
public:
    JsonData();
    virtual ~JsonData();

    string str() override;
    type_t Type() override;
    JsonData & add(shared_ptr<JsonData> data);
    friend class Factory;
protected:
    vector<shared_ptr<JsonData>> child;
};

typedef shared_ptr<JsonData> JsonData_PTR;