// Program to do stuff but not sure what yet.
#include <stdio.h>

int main( int argc, char ** argv ) {
	FILE *ff; // Setting file
	int c; // Setting int

	ff = fopen("contentfile.txt", "r"); // Open file.
	if (ff) {
		while ((c = getc(ff)) != EOF) {
			putchar(c); //Show file contents.
		}
		fclose(ff); // Close file.
	}
	if (!ff) {
		printf("Unable to open file\n"); // Error if no file.
		return 1;
	}
}
