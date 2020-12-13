
#ifdef _WIN32
	#include "header\headers.h"
#elif __linux__
    #include "header/headers.h"
#endif

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
const int MENUSIZE = 5;

int main(int argc, char const *argv[])
{
	setup();

	MemoHandler handler;

	while (true) {
		for (auto s : menu) cout << s << endl;
		cout << "select : ";
		int i;
		cin >> i;
		if (cin.fail() || i > MENUSIZE || i < 1) {
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
			for (int i = 0; i < 30; i++) cout << endl;
			handler.showAllMemo();
			cout << endl;
			cout << "press any key to continue. ";
			getchar();
			for (int i = 0; i < 30; i++) cout << endl;
			break;
		}
	}
	
	return 0;
}