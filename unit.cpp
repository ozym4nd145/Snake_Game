#include "unit.h"

void Unit::update_dir(int dir){
	//updates direction such that if dir is + then counter clockwise change , if negative then clockwise and 0 = no change
	curr_dir += 4 + dir;
	curr_dir %= 4;
}

void Unit::update_pos(){

	//updates position according to direction of motion.
	if(curr_dir == UP || curr_dir == DOWN){
		y += curr_dir - 2;
	}
	else{
		x += curr_dir - 1;
	}

	prev_dir = curr_dir;
}