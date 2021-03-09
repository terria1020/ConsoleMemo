#ifdef _WIN32
    #include "header\Misc.h"
#else
    #include "header/Misc.h"
#endif

#include <cstdlib>
#include <iostream>
#include <assert.h>
using std::cout;
using std::cin;

void setup () {
    if (isNeedSetup) {
        system("@echo off");
        //system("chcp 65001");//using korean in console // 원하는 대로 한글이 안 나옴. 일단 나중에 고쳐야 할 듯.
        system("chcp 949");
    }
    CLEARCON();
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
    cin.ignore(1, '\n');//buffer flush
    return index - 1;
}