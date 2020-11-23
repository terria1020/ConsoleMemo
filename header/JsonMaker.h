#pragma once
#include "Interfaces.h"
#include "JsonManager.h"

class JsonMaker : public JsonManager, public IJsonMaker {
public:
    JsonMaker(Json & json);
    ~JsonMaker();
    void makefile() override;
private:
};