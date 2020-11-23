#include "header/JsonParser.h"

JsonParser::JsonParser(Json & json)
    : JsonManager(json)
{
}
JsonParser::~JsonParser() {
}
bool JsonParser::parse() {
    //TODO: 파일 입력을 통해 json 읽기, 구조에 맞게 parse, 메모 구조에 저장
    return true;
}