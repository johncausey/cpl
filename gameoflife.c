// Game of Life
#include <ncurses.h> // stdio.h is included in ncurses
#include <string.h>

int main() {

	int row, col;
	char mesg[] = "Welcome.";

	initscr();
	getmaxyx(stdscr, row, col);
	mvprintw(row/3, (col-strlen(mesg))/2, "%s", mesg);

	mvprintw(row-2, 0, "This screen has %d rows and %d columns.\n", row, col);

	refresh();
	getch();
	endwin();

	return 0;
}
