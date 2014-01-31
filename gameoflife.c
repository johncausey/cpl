// Game of Life - in progress
#include <ncurses.h> // stdio.h is included in ncurses
#include <string.h> // memset
#include <unistd.h> // usleep

#define LIFE '0'
#define DEATH ' '
#define ROWSIZE 30
#define COLSIZE 70

int main() {
	// Initialize simulation area
	int row = ROWSIZE;
	int col = COLSIZE;
	int grid[row][col];
	memset(grid, DEATH, row*col*sizeof(int));
	srand(time(NULL));

	// Start simulation.
	int n, i, c, t;
	for (t = 0; t < 1000; t++) {
		initscr();
		int random_row = rand() % row;
		int random_col = rand() % col;
		grid[random_row][random_col] = LIFE;

		for (i = 0; i < row; i++) {
			for (c = 0; c < col; c++) {
				printw("%c ", grid[i][c]);
			}
			printw("\n");
		}

		// Finish window and refresh
		printw("\nGame of Life - No random variants\n\n");
		refresh();
		clear();
		usleep(30000);
	}

	// Close window and return to terminal
	endwin();
	return 0;
}

