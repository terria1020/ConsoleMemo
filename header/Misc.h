#pragma once
#include <iostream>
using namespace std;

const bool isNeedSetup = false;

#ifdef _WIN32
    #define CLEARCON() system("cls")
    const bool isNeedSetup = true;
#else
    #define CLEARCON() system("clear")
#endif

#define REPSTR(N, T) string{}.append(N, T)

const int IGNORESIZE = sizeof(char) + 1;

//Text Array size for input index bound check
const int TEXTSIZE_MENU = 6;
const int TEXTSIZE_THEME = 4;

void setup();
const int getIndex(const string coutText);