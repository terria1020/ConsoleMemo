#include "header/JsonMaker.h"
#include <fstream>

JsonMaker::JsonMaker(Json & json)
    : JsonManager(json)
{
}
JsonMaker::~JsonMaker() {
}
void JsonMaker::makefile() {

    //TODO: 양식에 맞추어 파일에 출력
    ofstream ofs;
    ofs.open("test.txt");
    ofs << json.str() << endl;
    ofs.close();
}