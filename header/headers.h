#pragma once

//user header
#ifdef _WIN32
    #include "Memo.h"
	#include "MemoHandler.h"
	#include "Misc.h"
	#include "ColorString.h"
#elif __linux__
    #include "Memo.h"
	#include "MemoHandler.h"
	#include "Misc.h"
	#include "ColorString.h"
#endif

//std base header
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>

//using
using namespace std;

//define
