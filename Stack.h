#ifndef STACK_H
#define STACK_H

#include "unit.h"

struct Stack{
	Stack(int x, int y):elem(x,y),next(NULL){}
	Stack():elem(0,0),next(NULL){}
	Unit elem;
	Stack* next;
};

#endif