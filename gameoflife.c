// Game of Life - in progress
#include <ncurses.h> // stdio.h is included in ncurses
#include <string.h> // memset
#include <unistd.h> // usleep

int main() {
	int row = 30;
	int col = 70;
	int grid[row][col];
	memset(grid, '.', row*col*sizeof(int));
	srand(time(NULL));

	// Start simulation.
	int n, i, c, t;
	for (t = 0; t < 1000; t++) {
		initscr();
		int random_row = rand() % 30;
		int random_col = rand() % 70;
		grid[random_row][random_col] = '1';

		for (i = 0; i < row; i++) {
			for (c = 0; c < col; c++) {
				printw("%c ", grid[i][c]);
			}
			printw("\n");
		}

		// Finish window and refresh
		printw("\nGame of Life\n\n");
		refresh();
		clear();
		usleep(30000);
	}
	endwin();
	return 0;
}

