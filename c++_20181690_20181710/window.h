#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <iostream>
#include <ncurses.h>
using namespace std;

class Window
{
private:
	WINDOW *win_start;
	WINDOW *win_board;

	WINDOW *win_level;
	WINDOW *win_push;
	WINDOW *win_step;
	WINDOW *win_end;

public:
	Window();
	WINDOW* getwinstart();
	WINDOW* getwinboard();

	WINDOW* getwinlevel();
	WINDOW* getwinpush();
	WINDOW* getwinstep();
	WINDOW* getwinend();

	void print_level(WINDOW *win_level, const int level);
	void print_push(WINDOW *win_push, const int push);
	void print_step(WINDOW *win_step, const int step);
	void print_board(WINDOW *win_board, int (*pushbox)[9][7], int *r, int *c);
	void print_end(WINDOW *win_end);

	void close(WINDOW *win);
};


#endif
