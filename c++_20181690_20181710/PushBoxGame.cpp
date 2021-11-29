#include <iostream>
#include <locale.h>
#include <ncurses.h>

#include "project.h"


using namespace std;

int pushBox[3][9][7]
={
	// 0: 빈부분, 1: 벽, 2: 상자, 3: 목적지, 4: 바깥부분, 7: 캐릭터
	{
		{4, 4, 4, 4, 4, 4, 4},
		{1, 1, 1, 1, 1, 4, 4},
		{1, 0, 0, 0, 1, 4, 4},
		{1, 3, 3, 3, 1, 4, 4},
		{1, 2, 2, 2, 1, 1, 4},
		{1, 0, 0, 0, 0, 1, 4},
		{1, 0, 7, 0, 0, 1, 4},
		{1, 1, 1, 1, 1, 1, 4},
		{4, 4, 4, 4, 4, 4, 4}
	},

	{
		{1, 1, 1, 1, 4, 4, 4},
		{1, 3, 0, 1, 1, 4, 4},
		{1, 3, 7, 0, 1, 4, 4},
		{1, 3, 0, 2, 1, 4, 4},
		{1, 1, 2, 0, 1, 1, 1},
		{4, 1, 0, 2, 0, 0, 1},
		{4, 1, 0, 0, 0, 0, 1},
		{4, 1, 0, 0, 1, 1, 1},
		{4, 1, 1, 1, 1, 4, 4}
	},
	{
		{4, 4, 4, 4, 4, 4, 4},
		{1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 3, 2, 3, 0, 1},
		{1, 0, 2, 3, 2, 0, 1},
		{1, 0, 3, 2, 3, 0, 1},
		{1, 0, 2, 3, 2, 0, 1},
		{1, 0, 0, 7, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1}
	}
	
};
int numOfGoal[3] = {3, 3, 6};


int main()
{	

	int c = 0, r = 0;
	int level = 0;
	int step = 0, push = 0;
	int key, success;
	int *goal;
	int num = 0;
	
	int (*pushbox)[9][7];
	pushbox = &pushBox[level];

	Setting();

	Window w = Window();
	Start s = Start();
	Game g = Game();

	goal = g.select_goal(numOfGoal[level], pushbox, &num);
	
	WINDOW *win_start = w.getwinstart();
	WINDOW *win_board = w.getwinboard();
	WINDOW *win_level = w.getwinlevel();
	WINDOW *win_push = w.getwinpush();
	WINDOW *win_step = w.getwinstep();
	WINDOW *win_end = w.getwinend();

	// 시작화면
	keypad(win_start, TRUE);
	int start = s.print_start(win_start);
	keypad(win_start, FALSE);
	w.close(win_start);
	if (start == 1); // START
	else if (start == 2) 
		endwin(); // END


	// 게임화면
	keypad(win_board, TRUE);
	
	while(1)
	{
		// 화면 초기화
		w.print_board(win_board, pushbox, &r, &c);
		w.print_level(win_level, level);
		werase(win_push);
		w.print_push(win_push, push);
		werase(win_step);
		w.print_step(win_step, step);

		// 게임 진행
		key = wgetch(win_board);
		success = g.moveCharacter(pushbox, goal, &r, &c, &push, key, num);
		step++;

		// 게임 탈출
		if (success == -2) break;

		// 게임 성공
		if (success == numOfGoal[level])
		{
			level++;
			step = 1;
			push = 0;
			pushbox = &pushBox[level];
			goal = g.select_goal(numOfGoal[level], pushbox, &num);

			if (level == 3)
			{
				endwin();
				break;
			}
		}
	}
	
	keypad(win_board, FALSE);

	// 종료화면
	w.close(win_board);
	w.close(win_level);
	w.close(win_push);
	w.close(win_step);

	w.print_end(win_end);
	getch();
	endwin();
	return 0;
}


