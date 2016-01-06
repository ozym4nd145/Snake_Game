#include <cstdlib>
#include <ncurses.h>
#include "snake.h"
#include "Stack.h"
#include <time.h>
#include "Score.h"
#include "food.h"


void food_gen(WINDOW* win,Snake* snake,std::pair<int,int>& coor_food){
	srand(time(NULL));		//generate pseudo random numbers
	int x,y;
	Stack* itr = snake->head();
	bool repeat= TRUE;
	while(repeat){			//runs loop until food doesn't overlap with snake and is inside BORDER
		itr = snake->head();
		repeat = FALSE;

		//condition to remain inside BORDER
		x = rand()%79 + COLS/2 - 39;
		y = rand()%29 + LINES/2 -14;

		//condition of no overlap with snake
		while(itr!=NULL){
			if(x == itr->elem.gx() && y== itr->elem.gy()){
				repeat = TRUE;
				break;
			}
			itr = itr->next;
		}
	}

	//updates coordinates of food
	coor_food.first = x;
	coor_food.second = y;

	//prints new food
	init_pair(7,COLOR_MAGENTA,COLOR_BLACK);
	attron(COLOR_PAIR(7)|A_BOLD);
	mvwprintw(win,y,x,"#");
	attroff(COLOR_PAIR(7)|A_BOLD);
}

void food_check(WINDOW* win,Snake* snake,std::pair<int,int>& coor_food, Score* score){
	Stack* itr = snake->head();
	//gets x and y coordinates of head.
	int x = itr->elem.gx();
	int y = itr->elem.gy();
	if(x==coor_food.first && y==coor_food.second){ //check overlapping with head
		snake->grow(1);	//attaches 1 unit to snake
		food_gen(win,snake,coor_food);	//generates new food
		score->update();	//updates score
		delay_ver -= 1000;		//speeds up the game
		delay_hor -= 1000;
	}
}