#pragma once
#include <string>
#include <vector>
#include "Memo.h"

using namespace std;

class MemoHandler {
public:
	MemoHandler();
	~MemoHandler();

	void newMemo();
	void newMemoTag();
	void rmMemo();
	void rmTag();

	void showMemo(const int index);
	void showAllMemo();
	
private:
	vector<Memo> memos;
	int theme;

	const string getAvailableMemoIndex();
};