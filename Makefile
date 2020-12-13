CC = g++
OPT = -std=c++14 -Wall
OBJS = ColorString.o Memo.o MemoHandler.o Misc.o main.o
TARGET = ConsoleMemo

ConsoleMemo : $(OBJS)
	# bin 폴더가 없으면 생성한다.
	# @가 앞에 붙어있으면 완벽히 쉘 명령어로 인식하는것 같다. if문의 파싱오류를  해결해준다.
	@ if [ ! -d "bin" ]; then mkdir bin; fi;
	$(CC) -o bin/$(TARGET) $(OBJS) $(OPT)

main.o : main.cpp
	$(CC) -c -o main.o main.cpp $(OPT)

ColorString.o : ColorString.cpp
	$(CC) -c -o ColorString.o ColorString.cpp $(OPT)

Memo.o : Memo.cpp
	$(CC) -c -o Memo.o Memo.cpp $(OPT)

MemoHandler.o : MemoHandler.cpp
	$(CC) -c -o MemoHandler.o MemoHandler.cpp $(OPT)

Misc.o : Misc.cpp
	$(CC) -c -o Misc.o Misc.cpp $(OPT)

clean : 
	rm *.o bin/$(TARGET)

install : 
	rm *.o
	mv bin/$(TARGET) /usr/bin