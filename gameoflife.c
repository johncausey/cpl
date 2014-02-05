// Conway's Game of Life with random life spawn inclusion
#include <ncurses.h> // stdio.h is included in ncurses
#include <string.h> // memset
#include <unistd.h> // usleep

#define LIFE '0'
#define DEATH ' '
#define ROWS 35 // 50 // 35
#define COLS 75 // 100 // 75
#define RANDOMLIFE 700
#define GENERATIONS 5000

int main(void) {
	// Set random
	srand(time(NULL));

	// Create boards
	int grid[ROWS][COLS];
	memset(grid, DEATH, ROWS*COLS*sizeof(int));
	int grid2[ROWS][COLS];
	memset(grid2, DEATH, ROWS*COLS*sizeof(int));

	// Set starter life
	initialize_board(grid, COLS, ROWS);
	initialize_board(grid2, COLS, ROWS);

	// Show game
	int n;
	int gen = 0;
	while (n = 0, n < GENERATIONS, ++n) {
		refresh_board(grid, gen);
		usleep(100000);
		repopulate(grid, grid2);
		copy_new_life(grid, grid2);
		gen++;
	}

	// End simulation
	endwin();
	return 0;
}

int initialize_board(int grid[ROWS][COLS]) {
	// Set random life
	int r;
	for (r = 0; r < RANDOMLIFE; r++) {
		int random_row = rand() % ROWS;
		int random_col = rand() % COLS;
		grid[random_row][random_col] = LIFE;
	}
}

int refresh_board(int grid[ROWS][COLS], int gen) {
	// Clear old window
	clear();

	// Build window
	initscr();

	// Set current generation
	int r, c;
	for (r = 0; r < ROWS; r++) {
		for (c = 0; c < COLS; c++) {
			printw("%c ", grid[r][c]);
		}
		printw("\n");
	}
	printw("\nGame of Life - %d random life spawns - %d Generations\n\n", RANDOMLIFE, gen);

	// Load window and refresh
	refresh();
}

int repopulate(int grid[ROWS][COLS], int grid2[ROWS][COLS]) {
	int r, c, n;
	for (r = 0; r < ROWS; r++) {
		for (c = 0; c < COLS; c++) {
			n = 0;
			if (grid[(r-1)][(c-1)] == LIFE) {
				n++; // -1,-1 top left
			}
			if (grid[(r-1)][c] == LIFE) {
				n++; // -1,0 top
			}
			if (grid[(r-1)][(c+1)] == LIFE) {
				n++; // -1,1 top right
			}
			if (grid[r][(c-1)] == LIFE) {
				n++; // 0,-1 left
			}
			if (grid[r][(c+1)] == LIFE) {
				n++; // 0,1 right
			}
			if (grid[(r+1)][(c-1)] == LIFE) {
				n++; // 1,-1 bottom left
			}
			if (grid[(r+1)][c] == LIFE) {
				n++; // 1,0 bottom
			}
			if (grid[(r+1)][(c+1)] == LIFE) {
				n++; // 1,1 bottom right
			}

			// Determine cell action
			if (grid[r][c] == LIFE) {
				if (n < 2) {
					if (chance_of_life() == 1) {
						// Under-population
						grid2[r][c] = DEATH;
					} else {
						grid2[r][c] = LIFE;
					}
				}
				if ((n == 2) || (n == 3)) {
					if (chance_of_life() == 1) {
						// Sustainable population
						grid2[r][c] = LIFE;
					} else {
						grid2[r][c] = DEATH;
					}
				}
				if (n > 3) {
					if (chance_of_life() == 1) {
						// Over-population
						grid2[r][c] = DEATH;
					} else {
						grid2[r][c] = LIFE;
					}
				}
			} else {
				if (n == 3) {
					if (chance_of_life() == 1) {
						// Reproduction
						grid2[r][c] = LIFE;
					} else {
						grid2[r][c] = DEATH;
					}
				} else {
					grid2[r][c] = DEATH;
				}
			}
		}
	}
}

int copy_new_life(int grid[ROWS][COLS], int grid2[ROWS][COLS]) {
	int r, c;
	for (r = 0; r < ROWS; r++) {
		for (c = 0; c < COLS; c++) {
			grid[r][c] = grid2[r][c];
		}
	}
}

int chance_of_life() {
	int c;
	c = (rand() % (1000 + 1));
	if (c > 10) {
		return 1;
	} else {
		return 0;
	}
}
