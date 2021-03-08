
//user header
#ifdef _WIN32
    #include "header\Memo.h"
	#include "header\MemoHandler.h"
	#include "header\Misc.h"
	#include "header\ColorString.h"
#else
	#include "header/Memo.h"
	#include "header/MemoHandler.h"
	#include "header/Misc.h"
	#include "header/ColorString.h"
#endif

//std base header
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>

//using
using namespace std;

extern vector<string> menu;
extern vector<string> themeMenu;

enum MENUTYPE {
	ADDMEMO = 1,
	ADDTAG,
	RMMEMO,
	RMTAG,
	SHOW,
	THEMESET
};

int main(int argc, char const *argv[])
{
	setup();

	MemoHandler handler;

	while (true) {
		for (auto s : menu) cout << s << endl;
		cout << "select : ";
		int i;
		cin >> i;
		if (cin.fail() || i > TEXTSIZE_MENU || i < 1) {
			cin.clear();
			cin.ignore(IGNORESIZE, '\n');
			cout << COLOR("[!] invaild menu number.", ERROR) << endl;
			continue;
		}

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
			//줄넘김
			for (int i = 0; i < 30; i++) cout << endl;
			handler.showAllMemo();
			cout << endl;
			cout << "press any key to continue. ";
			//입력 받을 때까지 대기
			getchar();
			for (int i = 0; i < 30; i++) cout << endl;
			break;
		case THEMESET:
			break;
		}
	}
	
	return 0;
}