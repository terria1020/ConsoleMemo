#pragma once
#include <iostream>
using namespace std;

#define REPSTR(N, T) string{}.append(N, T)

const int IGNORESIZE = sizeof(char) + 1;

void setup();
const int getIndex(const string coutText);