CC = g++
CFLAGS = -std=c++14 -Wall
OBJS = main.o Factory.o Json.o Misc.o JsonConsoleLogger.o JsonData.o JsonMaker.o JsonManager.o JsonParser.o JsonValue.o
TARGET = main

$(TARGET) : $(OBJS)
	@ if [ ! -d "bin" ]; then mkdir bin; fi;
	$(CC) -o bin/$(TARGET) $(OBJS) $(OPT)
	rm *.o

Misc.o : Misc.cpp
	g++ -c -o Misc.o Misc.cpp $(CFLAGS)

Factory.o : Factory.cpp
	g++ -c -o Factory.o Factory.cpp $(CFLAGS)

Json.o : Json.cpp
	g++ -c -o Json.o Json.cpp $(CFLAGS)

JsonConsoleLogger.o : JsonConsoleLogger.cpp
	g++ -c -o JsonConsoleLogger.o JsonConsoleLogger.cpp $(CFLAGS)

JsonData.o : JsonData.cpp
	g++ -c -o JsonData.o JsonData.cpp $(CFLAGS)
	
JsonMaker.o : JsonMaker.cpp
	g++ -c -o JsonMaker.o JsonMaker.cpp $(CFLAGS)

JsonManager.o : JsonManager.cpp
	g++ -c -o JsonManager.o JsonManager.cpp $(CFLAGS)

JsonParser.o : JsonParser.cpp
	g++ -c -o JsonParser.o JsonParser.cpp $(CFLAGS)

JsonValue.o : JsonValue.cpp
	g++ -c -o JsonValue.o JsonValue.cpp $(CFLAGS)

main.o : main.cpp
	g++ -c -o main.o main.cpp $(CFLAGS)

clean :
	rm *.o bin/$(TARGET)

install:
	mv $(TARGET) usr/bin/
