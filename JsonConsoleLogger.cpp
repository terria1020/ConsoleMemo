#include "header/JsonConsoleLogger.h"
#include <iostream>

JsonConsoleLogger::JsonConsoleLogger(Json & json)
    : JsonManager(json)
{
}
JsonConsoleLogger::~JsonConsoleLogger() {
}
void JsonConsoleLogger::log() {

    //TODO: 양식에 맞추어 console에 출력
    auto size = json.data.size();
    std::cout << "size : " << size << std::endl;
}