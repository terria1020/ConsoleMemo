CC = g++
OPT = -std=c++14 -Wall
OBJS = ColorString.o Memo.o MemoHandler.o Misc.o main.o
TARGET = ConsoleMemo

ConsoleMemo : $(OBJS)
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