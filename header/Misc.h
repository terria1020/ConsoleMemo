#pragma once
#include <iostream>
using namespace std;

#define REPSTR(N, T) string{}.append(N, T)

const int IGNORESIZE = sizeof(char) + 1;

//Text Array size for input index bound check
const int TEXTSIZE_MENU = 6;
const int TEXTSIZE_THEME = 4;

void setup();
const int getIndex(const string coutText);