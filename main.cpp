#include <iostream>
#include "header/Json.h"
#include "header/JsonValue.h"
#include "header/JsonConsoleLogger.h"
#include "header/JsonMaker.h"
#include "header/Misc.h"
#include "header/Factory.h"
#include <string>

using namespace std;

int main() {
    auto root = Factory::newJson();


    root->add("tag", Factory::newValue("hello world!"));
    
    auto sub = Factory::newJson();
    sub->add("subtag", Factory::newValue("hello world! sub"));
    sub->add("subtag2", Factory::newValue("hello world! sub2"));
    auto datas = Factory::newJsonData();
    datas->add(Factory::newValue("오늘 할 일"));
    datas->add(Factory::newValue("내일 할 일"));
    datas->add(Factory::newValue("모레 할 일"));
    sub->add("sub tags : ", datas);
    root->add("subcontents:", sub);
    cout << root->str() << endl;
    return 0;
}