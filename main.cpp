#include <iostream>
#include "header/Json.h"
#include "header/JsonValue.h"

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
    try {
        cout << root[2].str() << endl;    
    }
    catch (int e) {
        cerr << "invalid index." << endl;
    }
    
    return 0;
}