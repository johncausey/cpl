// Game of Life - in progress
#include <ncurses.h> // stdio.h is included in ncurses
#include <string.h> // memset
#include <unistd.h> // usleep

#define LIFE '0'
#define DEATH ' '
#define ROWSIZE 30
#define COLSIZE 70

int main(void) {

	// Create boards
	int grid[ROWSIZE][COLSIZE];
	memset(grid, DEATH, ROWSIZE*COLSIZE*sizeof(int));
	int grid2[ROWSIZE][COLSIZE];
	memset(grid2, DEATH, ROWSIZE*COLSIZE*sizeof(int));

	// Set starter life
	initialize_board(grid);
	initialize_board(grid2);

	// Show game
	int n;
	for (n = 0; n < 500; ++n) {
		refresh_board(grid);
		sleep(1);
		repopulate(grid, grid2);
	}

	// End program
	sleep(2);
	endwin();

	return 0;
}

int initialize_board(int grid[ROWSIZE][COLSIZE]) {

	// Set random life
	// srand(time(NULL));
	// int random_row = rand() % ROWSIZE;
	// int random_col = rand() % COLSIZE;
	// grid[random_row][random_col] = LIFE;

	grid[10][10] = LIFE;
	grid[10][11] = LIFE;
	grid[10][12] = LIFE;
	grid[11][10] = LIFE;
	grid[11][12] = LIFE;
	grid[12][12] = LIFE;
	grid[12][11] = LIFE;
	grid[12][10] = LIFE;
}

int refresh_board(int grid[ROWSIZE][COLSIZE]) {
	int r, c, n;
	for (n = 0; n < 1; n++) {
		// Build window
		initscr();

		// Iterate through board
		for (r = 0; r < ROWSIZE; r++) {
			for (c = 0; c < COLSIZE; c++) {
				printw("%c ", grid[r][c]);
			}
			printw("\n");
		}
		printw("\nGame of Life - No random variants\n\n");

		// Load window and refresh
		refresh();
		clear();
	}
}

int repopulate(int grid[ROWSIZE][COLSIZE], int grid2[ROWSIZE][COLSIZE]) {
	int r, c, n;
	memset(grid2, DEATH, ROWSIZE*COLSIZE*sizeof(int));
	for (r = 0; r < ROWSIZE; r++) {
		for (c = 0; c < COLSIZE; c++) {
			n = 0;
			if (grid[r-1][c-1] == LIFE) {
				++n; // -1,-1
			}
			if (grid[r-1][c] == LIFE) {
				++n; // -1,0
			}
			if (grid[r-1][c+1] == LIFE) {
				++n; // -1,1
			}
			if (grid[r][c-1] == LIFE) {
				++n; // 0,-1
			}
			if (grid[r][c+1] == LIFE) {
				++n; // 0,1
			}
			if (grid[r+1][c-1] == LIFE) {
				++n; // 1,-1
			}
			if (grid[r+1][c] == LIFE) {
				++n; // 1,0
			}
			if (grid[r+1][c+1] == LIFE) {
				++n; // 1,1
			}
			if (n < 2) {
				// Under-population death
				grid2[r][c] = DEATH;
			}
			if ((n == 2) || (n == 3)) {
				// Sustainable population
				grid2[r][c] = LIFE;
			}
			if (n > 3) {
				// Over-population death
				grid2[r][c] = DEATH;
			}
			if ((grid[r][c] == DEATH) && (n == 3)) {
				// Reproduction
				grid2[r][c] = LIFE;
			}
			n = 0;
			grid[r][c] = grid2[r][c];
		}
	}
}
