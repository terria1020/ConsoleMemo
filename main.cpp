#include <iostream>
#include "header/Json.h"
#include "header/JsonValue.h"
#include "header/JsonConsoleLogger.h"
#include "header/JsonMaker.h"
#include "header/Misc.h"
#include <string>

using namespace std;

int main() {
    Json root;

    root.add("tag", JsonValue{"hello world!"});
    root.add("tag2", JsonValue{"hello world!2"});
    
    Json sub;
    sub.elements.insert(make_pair("subtag", make_shared<JsonValue>(JsonValue{"myname is terria"})));

    root.elements.insert(make_pair("tag3", make_shared<Json>(sub)));
    cout << root.str();
    return 0;
}