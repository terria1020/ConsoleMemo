#pragma once
#include "Interfaces.h"

class JsonData : public IJsonData {
public:
    JsonData();
    virtual ~JsonData();

    string str() override;
    type_t Type() override;
private:
};