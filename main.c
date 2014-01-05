// Program to read a file and
// count newlines, tabs, and spaces.

#include <stdio.h>

int main( int argc, char ** argv ) {
	FILE *ff; // Setting file
	int c, tb, bl, nl; // Setting int
	tb = bl = nl = 0; // Values should equal 0 before while statement - counter values

	ff = fopen("contentfile.txt", "r"); // Read file
	if (ff) {
		while ((c = getc(ff)) != EOF) {
			// Read each character, putchar all and count nl, tb, bl
			if (c == '\t')
				++tb;
			if (c == ' ')
				++bl;
			if (c == '\n')
				++nl;
			putchar(c);
		}
		// Close file and present results
		fclose(ff);
		printf("\nThere are %d tabs, %d blanks, and %d newlines in file.\n", tb, bl, nl);
	}
	// Present error message if file fails to be opened/found
	if (!ff) {
		printf("Unable to open file\n");
		return 1;
	}
}
