#include <iostream>
#include "header/Json.h"
#include "header/JsonValue.h"
#include "header/JsonConsoleLogger.h"
#include "header/JsonMaker.h"
#include "header/Misc.h"
#include <string>

using namespace std;

int main() {
    auto root = Json::Factory::newJson();


    root->add("tag", JsonValue::Factory::newValue("hello world!"));
    
    auto sub = Json::Factory::newJson();
    sub->add("subtag", JsonValue::Factory::newValue("hello world! sub"));
    sub->add("subtag2", JsonValue::Factory::newValue("hello world! sub2"));
    root->add("subcontents:", sub);
    cout << root->str() << endl;
    return 0;
}