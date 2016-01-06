#include "collision.h"
#include "snake.h"
#include <ncurses.h>

bool collision_check(WINDOW* win, Snake* snake){
	Stack* itr = snake->head();
	int x = itr->elem.gx();				//gets coordinates of the head
	int y = itr->elem.gy();
	if(x>=(COLS/2)+40||x<=(COLS/2)-40||y>=(LINES/2)+15||y<=(LINES/2)-15){		//checks if head is on the border
		return TRUE;
	}
	itr=itr->next;
	while(itr!=NULL){		//checks collision of head with body
		if(x==itr->elem.gx()&&y==itr->elem.gy()){return TRUE;}
		itr = itr->next;
	}
	return FALSE;
}