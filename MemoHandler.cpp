#ifdef _WIN32
    #include "header\MemoHandler.h"
	#include "header\misc.h"
	#include "header\ColorString.h"
#elif __linux__
    #include "header/MemoHandler.h"
	#include "header/Misc.h"
	#include "header/ColorString.h"
#endif

#include <iostream>
#include <algorithm>
#include <sstream>

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
	cout << getAvailableMemoIndex();
	int index = getIndex("[new] select Memo index : ");

	if (index < 0 || index > memos.size()) {
		cout << COLOR("[!] invalid index.", ERROR) << endl;
		return;
	}
	cout << "tag : ";
	getline(cin, tag);

	memos[index].tag.push_back(tag);
}
void MemoHandler::rmMemo() {
	cout << getAvailableMemoIndex();
	int index = getIndex("[remove] select Memo index : ");

	if (index < 0 || index >= memos.size()) {
		cout << COLOR("[!] invalid index.", ERROR) << endl;
		return;
	}

	memos.erase(memos.begin() + index);
	cout << "remove success." << endl;
}
void MemoHandler::rmTag() {

	cout << getAvailableMemoIndex();
	int tindex;
	int index = getIndex("[remove] select Memo index : ");

	if (index < 0 || index >= memos.size()) {
		cout << COLOR("[!] invalid index.", ERROR) << endl;
		return;
	}

	tindex = getIndex("[remove] select Tag index : ");
	if (tindex < 0 || tindex > memos[index].tag.size()) {
		cout << COLOR("[!] invalid index.", ERROR) << endl;
		return;
	}

	memos[index].tag.erase(memos[index].tag.begin() + tindex);
	cout << "remove success." << endl;
}

void MemoHandler::showMemo(const int index) {
	cout << " # " << COLOR(" " + memos[index].name, MEMO) << endl;
	//백그라운드가 뒤에, 텍스트 색깔이 앞에꺼.

	for_each(memos[index].tag.begin(), memos[index].tag.end(), [] (string tag) {
		cout << "  >T> " << COLOR(tag, TAG) << endl;
	});
}

void MemoHandler::showAllMemo() {
	for (int i = 0; i < memos.size(); i++) {
		showMemo(i);
	}
}

const string MemoHandler::getAvailableMemoIndex() {
	ostringstream oss;

	oss << "available memo index : [ ";
	int i = 1;
	for_each(memos.begin(), memos.end(), [&i, &oss] (Memo & memo) {
		oss << i << " ";
		i++;
	});
	oss << "]" << endl;

	return oss.str();
}