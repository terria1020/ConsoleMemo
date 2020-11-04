#include <iostream>

#include <string>

#include <cstdio>

#include <vector>

#include <fstream>

#include <algorithm>

using namespace std;

 

struct Memo {

	string name;

	string tag[5];

 

	int tagindex;

 

	Memo(const string name);

	~Memo();

};

 

class MemoHandler {

public:

	MemoHandler();

	~MemoHandler();

 

	void newMemo();

	void newMemoTag();

	void rmMemo();

	void rmTag();

 

	void showMemo(const int index);

	

private:

	vector<Memo> memos;

	int theme;

	

	const string BgTheme();

	const string TextTheme();

};

 

void setup() {

	system("@echo off");

	system("chcp 65001");//using korean in console // 원하는 대로 한글이 안 나옴. 일단 나중에 고쳐야 할 듯.

	system("cls");

}

 

int main(int argc, char const *argv[])

{

	setup();

 

	MemoHandler handler;

 

	handler.newMemo();

	handler.newMemoTag();

	handler.newMemoTag();

	handler.showMemo(0);

	

	return 0;

}

 

Memo::Memo(const string name)

	: name(name),

	tagindex(0)

{

 

}

 

Memo::~Memo() {

 

}

 

 

MemoHandler::MemoHandler()

	: theme(0)

{

 

}

 

MemoHandler::~MemoHandler() {

 

}

 

 

void MemoHandler::newMemo() {

	string name;

	cout << "Memo Name : ";

	getline(cin, name);

	transform(name.begin(), name.end(), name.begin(), ::toupper);//lowercase to uppercase

 

	memos.push_back(Memo(name));

 

}

void MemoHandler::newMemoTag() {

	string tag;

	int index;

	cout << "select Memo index : ";

	cin >> index;

	cin.clear();

	cin.ignore(1, '\n');

 

	if (index < 0 || index > memos.size()) {

		cout << "[!] invalid index." << endl;

		return;

	}

	cout << "tag : ";

	getline(cin, tag);

 

	cout << "tag : " << tag << endl;

 

	memos[index].tag[memos[index].tagindex++] = tag;

}

void MemoHandler::rmMemo() {

 

}

void MemoHandler::rmTag() {

 

}

 

void MemoHandler::showMemo(const int index) {

	//printf(" # \x1b[92m\x1b[103m %s \x1b[0m\n", memos[index].name.c_str());

	cout << "\x1b" << TextTheme() << "\x1b" << BgTheme() << " " << memos[index].name << " \x1b[0m" << endl;

	//백그라운드가 뒤에, 텍스트 색깔이 앞에꺼.

	for (int i = 0; i < memos[index].tagindex; i++) {

		//printf("  >T> \x1b[94m\x1b[35m%s\x1b[0m\n", memos[index].tag[i].c_str());

		cout << "  >T> " << "\x1b" << "[94m" << "\x1b" << "[35m" << memos[index].tag[i] << "\x1b[0m" << endl;

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
