#include <ncurses.h>

int main(){
	WINDOW* new_win = newwin(LINES,COLS,0,0);
	mvwprintw(new_win,LINES/2,COLS/2,"Hello");
	wrefreah(new_win);
	system("PAUSE");
}