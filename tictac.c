// Tic Tac Toe game in C with computer player
#include <stdio.h>

#define PM 1 // Player mark of X
#define CM 2 // Computer mark of O


int print_board(int*, int);


int main(void) {
	int board[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // Initialize game board
	print_board(board, 9);
	return 0;
}


int print_board(int board[], int size) {	
	int n;
	for(n = 0; n < size; n++ ) {
		if(n % 3 == 0) {
			printf("\n\t");
		}
		printf("%d  ", board[n]);
		if(n == 8) {
			printf("\n\n");
		}
	}
}
