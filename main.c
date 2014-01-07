// Program to return basic data on a selected file.
#include <stdio.h>

int smfile(void);
int lafile(int *);

int main( int argc, char ** argv ) {
	FILE *ff; // File
	int c, si; // Character in file; File size
	float sf; // File size
	int nn = 0; // Newlines in file

	ff = fopen(argv[1], "r"); // Open file.
	// File exists.
	if (ff) {
		
		// Refactor 18-22
		printf("\nFile name: %s", argv[1]);
		fseek(ff, 0, SEEK_END);
		sf = si = ftell(ff);
		fseek(ff, 0, SEEK_SET);
		printf("\nFile size: %3.2fk (%d bytes)\n", (sf/1024), si );

		while ((c = getc(ff)) != EOF) {
			if(c == '\n') {
				++nn;
			}
			// putchar(c); //Show file contents - remove later.
		}

		// Decision to find last 10 or show entire file.
		if((nn <= 10)?(smfile()):(lafile(&nn)));
		fclose(ff); // Close file.
		return 0;
	}
	// File does not exist.
	else if (!ff) {
		printf("Unable to open file.\n"); // Error if no file.
		return 1;
	}
}


// Return entire file.
int smfile(void) {
	printf("\nPrint all lines option (10 or less).\n\n");
}

// Return last 10 lines.
int lafile(int *nn) {
	printf("\nPrint trailing lines, it has %d lines total.\n\n", *nn);
	return 0;
}
