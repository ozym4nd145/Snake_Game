#include "snake.h"
#include <unistd.h>

void Snake::update (WINDOW* level){
	Stack* itr = Snake::head(); //gets the head of the snake

	//prints the next position of head and in previous position adds a space and then updates the position to the new position.
	attron(COLOR_PAIR(6)|A_BOLD);
	if(itr->elem.gcurrent_dir() == UP ||itr->elem.gcurrent_dir() == DOWN){
		mvwprintw(level,itr->elem.gy() + itr->elem.gcurrent_dir() - 2,itr->elem.gx(),"@");
	}
	else{
		mvwprintw(level,itr->elem.gy(),itr->elem.gx() + itr->elem.gcurrent_dir() - 1,"@");	
	}
	attroff(COLOR_PAIR(6)|A_BOLD);

	mvwprintw(level,itr->elem.gy(),itr->elem.gx()," ");
	itr->elem.update_pos();

	itr=itr->next;

	//update the rest of the body in a similar way as above
	attron(COLOR_PAIR(5)|A_BOLD);
	while(itr != NULL){
		if(itr->elem.gcurrent_dir() == UP ||itr->elem.gcurrent_dir() == DOWN){
			mvwprintw(level,itr->elem.gy() + itr->elem.gcurrent_dir() - 2,itr->elem.gx(),"x");
		}
		else{
			mvwprintw(level,itr->elem.gy(),itr->elem.gx() + itr->elem.gcurrent_dir() - 1,"x");	
		}
		mvwprintw(level,itr->elem.gy(),itr->elem.gx()," ");
		itr->elem.update_pos();
		itr=itr->next;
	}
	attroff(COLOR_PAIR(5|A_BOLD));

}

void Snake::update_dir(int dir){
	//updates direction of head with the argument of funtion
	Stack* itr = Snake::head();
	itr->elem.update_dir(dir);

	//updates direction of rest of the body with the prev_dir of previous element;
	while(itr->next != NULL){
		itr->next->elem.update_dir(itr->elem.gprev_dir()-itr->next->elem.gcurrent_dir());
		itr = itr->next;
	}
}

void Snake::grow(int i){
	//Adds i units to the snake
	while(i--){
		Stack* new_head = new Stack;		//creates a new head to be pushed in stack of unit;
		new_head->elem.update_detail((top)->elem.gx(),(top)->elem.gy(),(top)->elem.gcurrent_dir(),(top)->elem.gprev_dir());
		new_head->elem.update_pos();
		new_head->next = this->top;
		this->top = new_head;
	}
}



void Snake::kill(){
	//Deallocates the space held by the units of Stack
	Stack* itr = top->next;
	while(itr != NULL){
		delete top;
		top = itr;
		itr = itr->next;
	}
}