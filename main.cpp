#include <iostream>
#include "header/Json.h"
#include "header/JsonValue.h"
#include "header/JsonConsoleLogger.h"
#include "header/JsonMaker.h"
#include "header/Misc.h"

using namespace std;

int main() {
    Json root;

    root.add("tag", JsonValue{"hello world!"});
    root.add("tag2", JsonValue{"hello world!2"});

    cout << root.str();
    return 0;
}