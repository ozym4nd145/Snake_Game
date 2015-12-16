#ifndef SCORE_H
#define SCORE_H

#include <ncurses.h>



#define SCORE 5
#define HEIGHT 30
#define WIDTH 80


class Score{
private:
	int score;
	int food;
public:
	Score();
	void print(WINDOW* win);
	void update();
	int get_score(){return score;}
};

#endif