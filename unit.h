#ifndef UNIT_H
#define UNIT_H
#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

class Unit{
private:
	int x;
	int y;
	int curr_dir;
	int prev_dir;
public:
	Unit(int x, int y):x(x),y(y),curr_dir(RIGHT),prev_dir(RIGHT){};
	
	void update_dir(int dir);				//Changes direction of motion of unit
	void update_pos();						//Update the x,y accordin to curr_dir and then prev_dir = curr_dir;

	int gx(){return x;}
	int gy(){return y;}
	int gcurrent_dir(){return curr_dir;}
	int gprev_dir(){return prev_dir;}
	
	void update_detail(int x_new, int y_new, int curr_new, int prev_new){x = x_new;y=y_new;curr_dir=curr_new;prev_dir=prev_new;}
};

#endif