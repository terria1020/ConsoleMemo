#ifdef _WIN32
    #include "header\misc.h"
#elif __linux__
    #include "header/misc.h"
#endif

#include <cstdlib>
#include <iostream>
#include <assert.h>
using std::cout;
using std::cin;

void setup () {
    #ifdef _WIN32
        system("@echo off");
        //system("chcp 65001");//using korean in console // 원하는 대로 한글이 안 나옴. 일단 나중에 고쳐야 할 듯.
        system("chcp 949");
        system("cls");
    #endif

    #ifdef __linux__
        system("clear");
    #endif
    return;
}

const int getIndex(const string coutText) {
    assert(coutText.size());

    int index;
	cout << coutText;
	cin >> index;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(IGNORESIZE, '\n');
        return -1;
	}
    cin.ignore(1, '\n');
    return index - 1;
}