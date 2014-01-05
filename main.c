// Program to read a file and
// count newlines, tabs, and spaces.
#include <stdio.h>

int main( int argc, char ** argv ) {
	FILE *ff; // Setting file
	int c; // Setting int

	ff = fopen("contentfile.txt", "r"); // Read file
	if (ff) {
		while ((c = getc(ff)) != EOF) {
			// Show file contents
			putchar(c);
		}
		// Close file and present results
		fclose(ff);
	}
	// Present error message if file fails to be opened/found
	if (!ff) {
		printf("Unable to open file\n");
		return 1;
	}
}
