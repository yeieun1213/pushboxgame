#include <iostream>
#include "window.h"

// 생성자
Window::Window()
{
	win_start = newwin(5, 13, 13, 8);
	win_board = newwin(15, 7, 13, 11);
	win_level = newwin(4, 7, 6, 4);
	win_push = newwin(4, 8, 6, 10);
	win_step = newwin(4, 8, 6, 17);
	win_end = newwin(15, 7, 13, 11);
}

WINDOW* Window::getwinstart() { return win_start; }
WINDOW* Window::getwinboard() { return win_board; }
WINDOW* Window::getwinlevel() { return win_level; }
WINDOW* Window::getwinpush() { return win_push; }
WINDOW* Window::getwinstep() { return win_step; }
WINDOW* Window::getwinend() { return win_end; }

void Window::print_level(WINDOW *win_level, const int level)
{
	mvwprintw(win_level, 1, 1, "Level");
	mvwprintw(win_level, 2, 3, "%d", level+1);
	wborder(win_level, '|', '|', '-', '-', '-', '-', '-', '-');

	wrefresh(win_level);
}

void Window::print_push(WINDOW *win_push, const int push)
{
	mvwprintw(win_push, 1, 2, "Push");
	mvwprintw(win_push, 2, 5, "%d", push);
	wborder(win_push, '|', '|', '-', '-', '-', '-', '-', '-');

	wrefresh(win_push);
}

void Window::print_step(WINDOW *win_step, const int step)
{
	mvwprintw(win_step, 1, 2, "Step");
	mvwprintw(win_step, 2, 5, "%d", step-1);
	wborder(win_step, '|', '|', '-', '-', '-', '-', '-', '-');

	wrefresh(win_step);
}

void Window::print_board(WINDOW *win_board, int (*pushbox)[9][7], int *r, int *c)
{	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if ((*pushbox)[i][j] == 0)
			{
				wattron(win_board, COLOR_PAIR(3));
				mvwprintw(win_board, i, j, "u2B1A");
				wattroff(win_board, COLOR_PAIR(3));
			}

			else if ((*pushbox)[i][j] == 1)
			{
				wattron(win_board, COLOR_PAIR(4));
				mvwprintw(win_board, i, j, "\u25A9");
				wattroff(win_board, COLOR_PAIR(4));
			}
			
			else if ((*pushbox)[i][j] == 2)
				mvwprintw(win_board, i, j, "\u2BBD");

			else if ((*pushbox)[i][j] == 3)
				mvwprintw(win_board, i, j, "\u2B1A");

			else if ((*pushbox)[i][j] == 4)
			{
				wattron(win_board, COLOR_PAIR(3));
				mvwprintw(win_board, i, j, "\u2B1A");
				wattroff(win_board, COLOR_PAIR(3));
			}

			else if ((*pushbox)[i][j] == 7)
			{
				*r = i;
				*c = j;
				wattron(win_board, COLOR_PAIR(5));
				mvwprintw(win_board, i, j, "\u2606");
				wattroff(win_board, COLOR_PAIR(5));
			}
		}
	}
	wrefresh(win_board);
}

void Window::print_end(WINDOW *win_end)
{
	attron(COLOR_PAIR(11));
//      	border('|','|','-','-','+','+','+','+');
	mvprintw(12, 8, "* GAME OVER *");
	attroff(COLOR_PAIR(11));
        
	attron(COLOR_PAIR(14));
//	mvprintw(6, 8, "Push Box Game");
	mvprintw(20, 4, "Press Any Key to Exit");
	attron(COLOR_PAIR(14));

	refresh();
}

// 윈도우 닫기
void Window::close(WINDOW *win)
{
	werase(win);
	wrefresh(win);
	delwin(win);
}
