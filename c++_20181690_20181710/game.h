#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
using namespace std;


class Game
{
public:
	Game();
	int moveCharacter(int (*pushbox)[9][7], int *goal, int *r, int *c, int *push, int key, int num);
	int* select_goal(int numOfGoal, int (*pushbox)[9][7], int *num);

};
#endif
