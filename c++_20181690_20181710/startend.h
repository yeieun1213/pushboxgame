#ifndef _STARTEND_H_
#define _STARTEND_H_

#include <ncurses.h>
#include <iostream>

class Start
{
private:
	int startx, starty;
                                                                                                                        
	const char *choices[2];
	int n_choices; 

public:
	Start();
	int print_start(WINDOW *win_start);
	void print_menu(WINDOW *menu_win, int highlight);
};

#endif
