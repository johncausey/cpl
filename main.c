// Program to return basic data on a selected file.
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int file_size(FILE *);
int file_location(char ** argv);
int whole_file(void);
int partial_file(int *);

int main( int argc, char ** argv ) {
	FILE *fp = fopen(argv[1], "r");      // File pointer
	int c;                               // Character in file; File size
	int nn = 0;                          // Newlines in file

	// File exists
	if (fp) {
		while ((c = getc(fp)) != EOF) {
			if(c == '\n') {
				++nn;
			}
		}
		printf("\n====================");
		file_location(argv);                                      // Show file path
		file_size(fp);                                            // Show file size
		if ((nn <= 10) ? (whole_file()) : (partial_file(&nn)));   // Show all or end
		printf("====================\n\n");
		fclose(fp);                                               // Close file
		return 0;
	}
	// File does not exist
	else if (!fp) {
		printf("Unable to open file.\n");               // Error if no file
		return 1;
	}
}

// Return file size
int file_size(FILE *in) {
	int si;
	float sf;
	fseek(in, 0, SEEK_END);
	sf = si = ftell(in);
	fseek(in, 0, SEEK_SET);
	printf("File size:      %3.2fk (%d bytes)\n", (sf/1024), si );
	return 0;
}

// Return file path
int file_location(char ** argv) {
	char buf[PATH_MAX];                            // limits.h
	char *pa = realpath(argv[1], buf);             // Realpath
	if (*pa) {
		printf("\nFile Location:  %s\n", buf);
	} else {
		printf("\nFile Location:  Not found\n");
	}
	return 0;
}

// todo
int whole_file(void) {
	printf("Print all lines option (10 or less).\n");
	return 0;
}

// todo
int partial_file(int *nn) {
	printf("Print trailing lines, it has %d lines total.\n", *nn);
	return 0;
}
