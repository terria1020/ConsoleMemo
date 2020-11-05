#ifdef _WIN32
    #include "header\MemoHandler.h"
	#include "header\misc.h"
#elif __linux__
    #include "header/MemoHandler.h"
	#include "header/misc.h"
#endif

#include <iostream>
#include <algorithm>




MemoHandler::MemoHandler()
	: theme(0)
{
}

MemoHandler::~MemoHandler() {
}


void MemoHandler::newMemo() {
	string name;
	cout << "[new] Memo Name : ";
	getline(cin, name);

	transform(name.begin(), name.end(), name.begin(), ::toupper);//lowercase to uppercase
	memos.push_back(Memo(name));

}
void MemoHandler::newMemoTag() {
	string tag;
	int index = getIndex("[new] select Memo index : ");

	if (index < 0 || index > memos.size()) {
		cout << "[!] invalid index." << endl;
		return;
	}
	cout << "tag : ";
	getline(cin, tag);

	memos[index].tag.push_back(tag);
}
void MemoHandler::rmMemo() {
	int index = getIndex("[remove] select Memo index : ");

	if (index < 0 || index > memos.size()) {
		cout << "[!] invalid index." << endl;
		return;
	}

	memos.erase(memos.begin() + index);
	cout << "remove success." << endl;
}
void MemoHandler::rmTag() {
	int tindex;
	int index = getIndex("[remove] select Memo index : ");

	if (index < 0 || index > memos.size()) {
		cout << "[!] invalid index." << endl;
		return;
	}

	tindex = getIndex("[remove] select Tag index : ");
	if (tindex < 0 || tindex > memos[index].tag.size()) {
		cout << "[!] invalid index." << endl;
		return;
	}

	memos[index].tag.erase(memos[index].tag.begin() + tindex);
	cout << "remove success." << endl;
}

void MemoHandler::showMemo(const int index) {
	cout << " # " << "\x1b" << TextTheme() << "\x1b" << BgTheme() << " " << memos[index].name << " \x1b[0m" << endl;
	//백그라운드가 뒤에, 텍스트 색깔이 앞에꺼.

	for_each(memos[index].tag.begin(), memos[index].tag.end(), [] (string tag) {
		cout << "  >T> " << "\x1b" << "[94m" << "\x1b" << "[35m" << tag << "\x1b[0m" << endl; });
}

void MemoHandler::showAllMemo() {
	for (int i = 0; i < memos.size(); i++) {
		showMemo(i);
	}
}


const string MemoHandler::BgTheme() {
	//TODO:
	/*swtich(theme) {
		case 1:
		return "";
		case 2:
		return "";
	}
	*/
	return "[103m";
}
const string MemoHandler::TextTheme() {
	//TODO:
	/*swtich(theme) {
		case 1:
		return "";
		case 2:
		return "";
	}
	*/
	return "[92m";
}