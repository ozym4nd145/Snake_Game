#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <ncurses.h>
#include "snake.h"
#include "Stack.h"
#include <time.h>
#include "Score.h"
extern int delay;
//food_check() checks if food has been consumed and if yes then generates new food and also extends the snake accordingly as well as speeds up the game
void food_check(WINDOW* win,Snake* snake,std::pair<int,int>& coor_food, Score* score); 	

//food_gen() generates the food such that it doesn't overlap with snake and stays within the border.
void food_gen(WINDOW* win,Snake* snake,std::pair<int,int>& coor_food);


#endif