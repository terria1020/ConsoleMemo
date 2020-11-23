#pragma once
#include "Interfaces.h"
#include  "JsonManager.h"

class JsonParser : public JsonManager, public IJsonParser {
public:
    JsonParser(Json & json);
    ~JsonParser();
    virtual bool parse() override;
};