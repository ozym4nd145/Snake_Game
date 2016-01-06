#include "level.h"
#include <ncurses.h>
#include <string.h>

void draw_level(WINDOW* win){
	int i;
	attron(COLOR_PAIR(4)|A_UNDERLINE);
	mvwprintw(win,0,(COLS-strlen("Developed By Suyash Agrawal"))/2,"Developed By Suyash Agrawal");
	attroff(COLOR_PAIR(4)|A_UNDERLINE);
	attron(COLOR_PAIR(1)|A_BOLD|A_STANDOUT);
	mvwprintw(win,2,(COLS-strlen("Snake Game"))/2,"Snake Game");
	attroff(COLOR_PAIR(1)|A_BOLD|A_STANDOUT);
	attron(COLOR_PAIR(6)|A_DIM);
	mvwprintw(win,3,(COLS-strlen("Instruction - Use Right/Left arrow to turn accordingly(relative to the motion of snake)"))/2,"Instruction - Use Right/Left arrow to turn accordingly(relative to the motion of snake)");
	mvwprintw(win,LINES/2,(COLS-strlen("Press any key to start.."))/2,"Press any key to start..");
	attroff(COLOR_PAIR(6)|A_DIM);
	attron(COLOR_PAIR(3)|A_DIM);

	// Draws the Border
	for(i=(COLS/2)-40;i<=(COLS/2)+40;i++){
		mvwprintw(win,(LINES/2)-15,i,"=");
		mvwprintw(win,(LINES/2)+15,i,"=");
	}
	for(i=(LINES/2)-15;i<=(LINES/2)+15;i++){
		mvwprintw(win,i,(COLS/2)-40,"|");
		mvwprintw(win,i,(COLS/2)+40,"|");
	}
	attroff(COLOR_PAIR(3)|A_DIM);
	wrefresh(win);
}