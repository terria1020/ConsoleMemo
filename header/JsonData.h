#pragma once
#include "Interfaces.h"
#include <memory>
using std::shared_ptr;

class JsonData : public IJsonData {
public:
    JsonData();
    virtual ~JsonData();

    string str() override;
    type_t Type() override;
private:
    shared_ptr<JsonData> child;
};

typedef shared_ptr<JsonData> JsonData_PTR;