#include "header/JsonConsoleLogger.h"
#include "header/Misc.h"
#include "header/Interfaces.h"
#include <algorithm>
#include <iostream>
#include <sstream>

JsonConsoleLogger::JsonConsoleLogger(Json & json)
    : JsonManager(json)
{
}
JsonConsoleLogger::~JsonConsoleLogger() {
}
void JsonConsoleLogger::log() {

    //TODO: 양식에 맞추어 console에 출력
    ostringstream oss;
    Json & root = json;

    oss << blank(level - 1) << "{" << endl;

    oss << blank(level) << root.str() << endl;

    oss << blank(level - 1) << "}" << endl;

    cout << oss.str();
}