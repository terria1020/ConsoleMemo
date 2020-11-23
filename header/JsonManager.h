#pragma once
#include "Interfaces.h"
#include "Json.h"

class JsonManager {
public:
    JsonManager(Json & json);
    virtual ~JsonManager();
protected:
    Json & json;
};