// Program to return the last 10 lines of a file.
#include <stdio.h>

int smfile();
int lafile(int *);

int main( int argc, char ** argv ) {
	FILE *ff;
	int c;
	int nn = 0;


	ff = fopen("contentfile.txt", "r"); // Open file.
	// File exists.
	if (ff) {
		while ((c = getc(ff)) != EOF) {
			if(c == '\n') {
				++nn;
			}
			//putchar(c); //Show file contents.
		}
		if((nn <= 10)?(smfile()):(lafile(&nn)));
		fclose(ff); // Close file.
	}
	// File does not exist.
	if (!ff) {
		printf("Unable to open file.\n"); // Error if no file.
		return 1;
	}
}


int smfile() {
	printf("Print all lines option (10 or less).\n");
	return 0;
}


int lafile(int *nn) {
	printf("Print trailing lines, it has %d lines total.\n", *nn);
	return 0;
}
