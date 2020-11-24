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

#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#define REPSTR(N, T) string{}.append(N, T)

vector<string> menu = {
	REPSTR(30, '-'),
	"< Console Memo >",
	"this program use to record memo.",
	REPSTR(30, '-'),
	"1 : Add Memo",
	"2 : Add memo-tag",
	"3 : remove Memo",
	"4 : remove memo-tag",
	"5 : show All Memos",
	REPSTR(30, '-')
};

enum MENUTYPE {
	ADDMEMO = 1,
	ADDTAG,
	RMMEMO,
	RMTAG,
	SHOW,
};

int main(int argc, char const *argv[])
{
	
	setup();

	MemoHandler handler;
/*
	handler.newMemo();
	handler.newMemoTag();
	handler.newMemo();
	
	handler.newMemoTag();
	handler.showMemo(0);
	handler.showMemo(1);
	
	handler.rmMemo();
	handler.rmTag();

	handler.showAllMemo();*/

	while (true) {
		for (auto s : menu) cout << s << endl;
		cout << "select : ";
		int i;
		cin >> i;

		cin.ignore(256, '\n');
		switch (i) {
		case ADDMEMO:
			handler.newMemo();
			break;
		case ADDTAG:
			handler.newMemoTag();
			break;
		case RMMEMO:
			handler.rmMemo();
			break;
		case RMTAG:
			handler.rmTag();
			break;
		case SHOW:
			for (int i = 0; i < 10; i++) cout << endl;
			handler.showAllMemo();
			cout << endl;
			cout << "press any key to continue. ";
			char c = getchar();
			for (int i = 0; i < 10; i++) cout << endl;
			break;
		}
	}
	
	return 0;
}