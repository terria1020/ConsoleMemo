#include <iostream>
#include "header\Memo.h"
#include "header\MemoHandler.h"
using namespace std;

void setup() {
	system("@echo off");
	//system("chcp 65001");//using korean in console // 원하는 대로 한글이 안 나옴. 일단 나중에 고쳐야 할 듯.
	system("chcp 949");
	system("cls");
}

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

	handler.showAllMemo();
	
	return 0;
}