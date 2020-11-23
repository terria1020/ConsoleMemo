#include <iostream>
#include "header/Json.h"
#include "header/JsonValue.h"
#include "header/JsonConsoleLogger.h"
#include "header/JsonMaker.h"

using namespace std;

int main() {
    Json root;
    root.addKey("testkey")
    .addValue("testdata");

    Json sub;
    sub.addKey("name").addValue("today's date");
    sub.addJson(Json{}.
    addKey("tag").
    addValue("hello world!"));

    root.addJson(sub);
    
    cout << root.str() << endl;
    cout << root[1].str() << endl;
    
    return 0;
}