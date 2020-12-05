#pragma once
#include "Interfaces.h"
#include <memory>

using namespace std;

class JsonData : public IJsonData {
public:
    JsonData();
    virtual ~JsonData();

    string str() override;
    type_t Type() override;
};

typedef shared_ptr<JsonData> JsonData_PTR;