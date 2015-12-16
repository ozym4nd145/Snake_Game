#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <ncurses.h>
#include "unit.h"
#include "Stack.h"

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3


class Snake{
private:
	Stack* top;
public:
	Snake(int x, int y){top = new Stack(x,y);}

	void update(WINDOW* level);	//Draws the snake on screen and updates the coordinates of units according to their current moving direction
	void update_dir(int dir);	//Updates the direction of units comprising snake.
	Stack* head(){return top;}	//return pointer to head of snake
	void push(Stack* new_head){new_head->next = top; top = new_head;} //Replaces the head of snake (used when attaching a new unit after consumption of food)
	void grow(int i);	//Attaches i units to snake

	void kill(); //Deallocates space of all the units to kill snake.

	~Snake(){kill();} //Destructor
};
#endif