#pragma once
#include "Interfaces.h"
#include "JsonManager.h"

class JsonConsoleLogger : public JsonManager, public IJsonConsoleLogger {
public:
    JsonConsoleLogger(Json & json);
    ~JsonConsoleLogger();
    void log() override;

    int level;
};