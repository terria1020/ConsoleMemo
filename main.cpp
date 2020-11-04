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


MemoHandler::MemoHandler() {

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

	fflush(stdin);

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
	printf(" # \x1b[92m\x1b[103m %s \x1b[0m\n", memos[index].name.c_str());
	for (int i = 0; i < memos[index].tagindex; i++) {
		printf("  >T> \x1b[94m\x1b[35m%s\x1b[0m\n", memos[index].tag[i].c_str());
	}
}