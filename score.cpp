#include <ncurses.h>
#include <string.h>
#include "Score.h"

Score::Score():score(0),food(0){
		attron(COLOR_PAIR(6)|A_UNDERLINE|A_BOLD);
		mvwprintw(stdscr,(2*LINES)/3 + HEIGHT/3, COLS/2 - strlen("Score -     "),"Score - %d",score);
		attroff(COLOR_PAIR(6)|A_UNDERLINE|A_BOLD);
	}

void Score::print(WINDOW* win){
		attron(COLOR_PAIR(6)|A_UNDERLINE|A_BOLD);
		mvwprintw(win,(2*LINES)/3 + HEIGHT/3, (COLS - strlen("Score -     "))/2,"Score - %d",score);
		attroff(COLOR_PAIR(6)|A_UNDERLINE|A_BOLD);
	}

void Score::update(){
		food++;
		score += SCORE*food; //1st fish = 5 points, 2nd fish = 10 points, 3rd fish = 15 points ...
	}