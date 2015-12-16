#ifndef COLLISION_H
#define COLLISION_H

#include <ncurses.h>
#include "snake.h"

bool collision_check(WINDOW* win, Snake* snake);

#endif