#include <iostream>
#include <ncurses.h>
#include "setting.h"

void Setting()
{
	setlocale(LC_ALL, "");
	initscr();
	noecho();
	curs_set(0);
	resize_term(29, 29);

	start_color();

	init_pair(1, COLOR_BLUE, COLOR_WHITE);
	init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(3, COLOR_BLACK, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(11, COLOR_BLUE, COLOR_WHITE);
	init_pair(14, COLOR_BLUE, COLOR_BLACK);

	attron(COLOR_PAIR(1));
	border('|', '|', '-', '-', '+', '+', '+', '+');
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(4));
	mvprintw(3, 8, "Push Box Game");
	attroff(COLOR_PAIR(4));
	refresh();
}
