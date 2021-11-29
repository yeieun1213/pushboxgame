CC=g++
CPPFLAGS=-W -Wall

all:project

project:setting.o game.o window.o startend.o PushBoxGame.o
	$(CC) $(CPPFLAGS) -o project setting.o game.o window.o startend.o PushBoxGame.o -lncursesw

setting.o:setting.cpp
	$(CC) $(CPPFLAGS) -c -o setting.o setting.cpp

game.o:game.cpp
	$(CC) $(CPPFLAGS) -c -o game.o game.cpp

window.o:window.cpp
	$(CC) $(CPPFLAGS) -c -o window.o window.cpp

startend.o:startend.cpp
	$(CC) $(CPPFLAGS) -c -o startend.o startend.cpp

PushBoxGame.o:PushBoxGame.cpp
	$(CC) $(CPPFLAGS) -c -o PushBoxGame.o PushBoxGame.cpp

clean:
	rm -rf *.o
