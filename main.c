// Program to return basic data on a selected file.
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int flsize(FILE *, float *, int *);
int lngpath(char ** argv);
int smfile(void);
int lafile(int *);

int main( int argc, char ** argv ) {
	FILE *fp = fopen(argv[1], "r");      // File pointer
	int c, si;                           // Character in file; File size
	float sf;                            // File size
	int nn = 0;                          // Newlines in file

	// File exists
	if (fp) {
		while ((c = getc(fp)) != EOF) {
			if(c == '\n') {
				++nn;
			}
		}
		printf("\n====================");
		lngpath(argv);                                  // Show file path
		flsize(fp, &sf, &si);                           // Show file size
		if ((nn <= 10) ? (smfile()) : (lafile(&nn)));   // Show all or end
		printf("====================\n");
		fclose(fp);                                     // Close file.
		return 0;
	}
	// File does not exist.
	else if (!fp) {
		printf("Unable to open file.\n");               // Error if no file.
		return 1;
	}
}

int flsize(FILE *in, float *sf, int *si) {
	fseek(in, 0, SEEK_END);
	*sf = *si = ftell(in);
	fseek(in, 0, SEEK_SET);
	printf("File size:      %3.2fk (%d bytes)\n", (*sf/1024), *si );
	return 0;
}

// Return file path.
int lngpath(char ** argv) {
	char buf[PATH_MAX];                            // Filepath max size
	char *pa = realpath(argv[1], buf);             // Realpath
	if (*pa) {
		printf("\nFile Location:  %s\n", buf);
	} else {
		printf("\nFile Location:  Not found\n");
	}
	return 0;
}

// Return entire file.
int smfile(void) {
	printf("Print all lines option (10 or less).\n");
	return 0;
}

// Return last 10 lines.
int lafile(int *nn) {
	printf("Print trailing lines, it has %d lines total.\n", *nn);
	return 0;
}
