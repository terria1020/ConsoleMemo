#include "header/JsonValue.h"
#include <iostream>

JsonValue::JsonValue() {
}
JsonValue::JsonValue(const string value)
    : value(value)
{
}
JsonValue::~JsonValue() {
}

string JsonValue::str() {
    return "\"" + value + "\"";
}
type_t JsonValue::Type() {
    static type_t type = TYPE::VALUE;
    return type;
}