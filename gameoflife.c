// Conway's Game of Life with random life spawn inclusion
#include <ncurses.h> // stdio.h is included in ncurses
#include <string.h> // memset
#include <unistd.h> // usleep

#define LIFE '0'
#define DEATH ' '
#define ROWSIZE 35
#define COLSIZE 75
#define RANDOMLIFE 700
#define GENERATIONS 5000

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
	int gen = 0;
	while (n = 0, n < GENERATIONS, ++n) {
		refresh_board(grid, gen);
		usleep(50000);
		repopulate(grid, grid2);
		copy_new_life(grid, grid2);
		gen++;
	}

	// End simulation
	endwin();
	return 0;
}

int initialize_board(int grid[ROWSIZE][COLSIZE]) {
	// Set random life
	int r;
	srand(time(NULL));
	for (r = 0; r < RANDOMLIFE; r++) {
		int random_row = rand() % ROWSIZE;
		int random_col = rand() % COLSIZE;
		grid[random_row][random_col] = LIFE;
	}

	// Generate stable cell windmill
	grid[10][10] = LIFE;
	grid[10][11] = LIFE;
	grid[10][12] = LIFE;
	grid[11][10] = LIFE;
	grid[11][12] = LIFE;
	grid[12][12] = LIFE;
	grid[12][11] = LIFE;
	grid[12][10] = LIFE;
}

int refresh_board(int grid[ROWSIZE][COLSIZE], int gen) {
	// Clear old window
	clear();

	// Build window
	initscr();

	// Set current generation
	int r, c;
	for (r = 0; r < ROWSIZE; r++) {
		for (c = 0; c < COLSIZE; c++) {
			printw("%c ", grid[r][c]);
		}
		printw("\n");
	}
	printw("\nGame of Life - %d random life spawns - %d Generations\n\n", RANDOMLIFE, gen);

	// Load window and refresh
	refresh();
}

int repopulate(int grid[ROWSIZE][COLSIZE], int grid2[ROWSIZE][COLSIZE]) {
	int r, c, n;
	for (r = 0; r < ROWSIZE; r++) {
		for (c = 0; c < COLSIZE; c++) {
			n = 0;
			if (grid[(r-1)][(c-1)] == LIFE) {
				n++; // -1,-1
			}
			if (grid[(r-1)][c] == LIFE) {
				n++; // -1,0
			}
			if (grid[(r-1)][(c+1)] == LIFE) {
				n++; // -1,1
			}
			if (grid[r][(c-1)] == LIFE) {
				n++; // 0,-1
			}
			if (grid[r][(c+1)] == LIFE) {
				n++; // 0,1
			}
			if (grid[(r+1)][(c-1)] == LIFE) {
				n++; // 1,-1
			}
			if (grid[(r+1)][c] == LIFE) {
				n++; // 1,0
			}
			if (grid[(r+1)][(c+1)] == LIFE) {
				n++; // 1,1
			}

			// Determine cell action
			if (grid[r][c] == LIFE) {
				if (n < 2) {
					// Under-population
					grid2[r][c] = DEATH;
				}
				if ((n == 2) || (n == 3)) {
					// Sustainable population
					grid2[r][c] = LIFE;
				}
				if (n > 3) {
					// Over-population
					grid2[r][c] = DEATH;
				}
			} else {
				if (n == 3) {
					// Reproduction
					grid2[r][c] = LIFE;
				} else {
					grid2[r][c] = DEATH;
				}
			}
		}
	}
}

int copy_new_life(int grid[ROWSIZE][COLSIZE], int grid2[ROWSIZE][COLSIZE]) {
	int r, c;
	for (r = 0; r < ROWSIZE; r++) {
		for (c = 0; c < COLSIZE; c++) {
			grid[r][c] = grid2[r][c];
		}
	}
}
