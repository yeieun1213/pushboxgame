#include <iostream>
#include <ncurses.h>
#include "game.h"

Game::Game()
{ }

// 캐릭터 움직이
int Game::moveCharacter(int (*pushbox)[9][7], int *goal, int *r, int *c, int *push, int key, int num)
{
        // 0: 빈부분, 1 : 벽, 2 : 상자, 3 :목적지, 4 : 바깥부분, 7 : 캐릭터
        switch(key)
        {
		// 게임 탈출(backspace)
		case KEY_BACKSPACE:
			return -2;
		case KEY_UP:
		// 이동방향에 벽이 있거나
			if (((*pushbox)[*r-1][*c] == 1) || ((*pushbox)[*r-1][*c] == 2 && (*pushbox)[*r-2][*c] == 1))
				return -1;
			// 상자가 2개 이상
			if (((*pushbox)[*r-1][*c] == 2) && ((*pushbox)[*r-2][*c] == 2))
				return -1;
			// 이동방향에 상자, 상자 앞이 빈부분이거나, 목적지
			if ((*pushbox)[*r-1][*c] == 2 && ((*pushbox)[*r-2][*c] == 0 || (*pushbox)[*r-2][*c] == 3))
			{
				(*pushbox)[*r-2][*c] = 2;
				(*push)++;
				(*pushbox)[*r-1][*c] = 7;
				(*pushbox)[*r][*c] = 0;
				(*r)--;
			}
			// 이동방향이 빈부분이거나 목적지 
			if(((*pushbox)[*r-1][*c] == 0) || ((*pushbox)[*r-1][*c] == 3))
			{
				(*pushbox)[*r][*c] = 0;
				(*pushbox)[*r-1][*c] = 7;
				(*r)--;
			}
			break;
			
		// 0: 빈부분, 1: 벽, 2: 상자, 3: 목적지, 4: 바깥부분, 7: 캐릭터
		case KEY_DOWN:
			// 이동방향에 벽이 있거나
                        if (((*pushbox)[*r+1][*c] == 1) || ((*pushbox)[*r+1][*c] == 2 && (*pushbox)[*r+2][*c] == 1))
				return -1;
                        // 상자가 2개 이상
                        if (((*pushbox)[*r+1][*c] == 2) && ((*pushbox)[*r+2][*c] == 2))
				return -1;
                        // 이동방향에 상자, 상자 앞이 빈부분이거나, 목적지
                        if ((*pushbox)[*r+1][*c] == 2 && ((*pushbox)[*r+2][*c] == 0 || (*pushbox)[*r+2][*c] == 3))
                        {
				(*pushbox)[*r+2][*c] = 2;
				(*push)++;
				(*pushbox)[*r+1][*c] = 7;
				(*pushbox)[*r][*c] = 0;
				(*r)++;
			}       
			// 이동방향이 빈부분이거나 목적지 
			if(((*pushbox)[*r+1][*c] == 0) || ((*pushbox)[*r+1][*c] == 3))
			{
				(*pushbox)[*r][*c] = 0;
				(*pushbox)[*r+1][*c] = 7;
				(*r)++;
			}       
			break;

		// 0: 빈부분, 1: 벽, 2: 상자, 3: 목적지. 4: 바깥부분, 7: 캐릭터
		case KEY_RIGHT:
			// 이동방향에 벽이 있거나
			if (((*pushbox)[*r][*c+1] == 1) || ((*pushbox)[*r][*c+1] == 2 && (*pushbox)[*r][*c+2] == 1))
				return -1;
			// 상자가 2개 이상
			if (((*pushbox)[*r][*c+1] == 2) && ((*pushbox)[*r][*c+2] == 2))
				return -1;
			// 이동방향에 상자, 상자 앞이 빈부분이거나, 목적지
			if ((*pushbox)[*r][*c+1] == 2 && ((*pushbox)[*r][*c+2] == 0 || (*pushbox)[*r][*c+2] == 3))
			{
				(*pushbox)[*r][*c+2] = 2;
				(*push)++;
				(*pushbox)[*r][*c+1] = 7;
				(*pushbox)[*r][*c] = 0;
                                (*c)++;
			}       
                                // 이동방향이 빈부분이거나 목적지 
 			if(((*pushbox)[*r][*c+1] == 0) || ((*pushbox)[*r][*c+1] == 3))
			{
				(*pushbox)[*r][*c] = 0;
				(*pushbox)[*r][*c+1] = 7;
				(*c)++;
			}       
			break;


				// 0: 빈부분, 1: 벽, 2: 상자, 3: 목적지, 4: 바깥부분, 7: 캐릭터
		case KEY_LEFT:
			// 이동방향에 벽이 있거나
			if (((*pushbox)[*r][*c-1] == 1) || ((*pushbox)[*r][*c-1] == 2 && (*pushbox)[*r][*c-2] == 1))
				return -1;
                                // 상자가 2개 이상
			if (((*pushbox)[*r][*c-1] == 2) && ((*pushbox)[*r][*c-2] == 2))
				return -1;
			// 이동방향에 상자, 상자 앞이 빈부분이거나, 목적지
			if ((*pushbox)[*r][*c-1] == 2 && ((*pushbox)[*r][*c-2] == 0 || (*pushbox)[*r][*c-2] == 3))
			{
				(*pushbox)[*r][*c-2] = 2;
				(*push)++;
				(*pushbox)[*r][*c-1] = 7;
				(*pushbox)[*r][*c] = 0;
				(*c)--;
			}      
			// 이동방향이 빈부분이거나 목적지 
			if(((*pushbox)[*r][*c-1] == 0) || ((*pushbox)[*r][*c-1] == 3))
			{
				(*pushbox)[*r][*c] = 0;
				(*pushbox)[*r][*c-1] = 7;
				(*c)--;
			}      
			break;
	}
	int success = 0;
	for (int i = 0; i < num; i+=2)
	{
		if ((*pushbox)[goal[i]][goal[i+1]] == 0)
			(*pushbox)[goal[i]][goal[i+1]] = 3;
		else if ((*pushbox)[goal[i]][goal[i+1]] == 2)
			success++;
	}
        
    return (success);
}

// 목적지 위치 설정
int* Game::select_goal(int numOfGoal, int (*pushbox)[9][7], int *num)
{

	int n = 0;
	int *Goal;

	// 동적할당 배열 초기화
	Goal = new int[numOfGoal * 2];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			// 목적지 위치 Goal 배열에 저장
			if ((*pushbox)[i][j] == 3)
			{
				Goal[n] = i;
				Goal[n+1] = j;
				n += 2;
			}
		}
	}
	// Goal 크기 
	*num = n;

	return Goal;
}


