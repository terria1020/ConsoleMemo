#include <iostream>

#ifdef _WIN32
    #include "header\Memo.h"
	#include "header\MemoHandler.h"
	#include "header\misc.h"
#elif __linux__
    #include "header/Memo.h"
	#include "header/MemoHandler.h"
	#include "header/misc.h"
#endif
using namespace std;

int main(int argc, char const *argv[])
{
	setup();

	MemoHandler handler;

	handler.newMemo();
	handler.newMemoTag();
	handler.newMemo();
	
	handler.newMemoTag();
	handler.showMemo(0);
	handler.showMemo(1);
	
	handler.rmMemo();
	handler.rmTag();

	handler.showAllMemo();
	
	return 0;
}