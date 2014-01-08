// Program to return basic data on a selected file.
#include <limits.h> //PATH_MAX
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

int file_size(FILE *);
int file_location(char ** argv, char, char *);
int file_moditifation(char ** argv);
int whole_file(void);
int partial_file(int *);

int main( int argc, char ** argv ) {
	FILE *fp = fopen(argv[1], "r");      // File pointer
	int c;                               // Character in file; File size
	int nn = 0;                          // Newlines in file
	char buf[PATH_MAX];                  // File path buf
	char *pa = realpath(argv[1], buf);   // Get file path

	// File exists
	if (fp) {
		while ((c = getc(fp)) != EOF) {
			if(c == '\n') {
				++nn;
			}
		}
		printf("\n====================");
		file_location(argv, *pa, buf);                            // Show file path
		file_modification(argv);                                  // Show file last modified
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
	printf("File size:%13s%3.2fk (%d bytes)\n", "", (sf/1024), (si));
	return 0;
}

// Return file path
int file_location(char ** argv, char pa, char *buf) {
	printf("\nFile location:%9s%s\n", "", buf);
	return 0;
}

// Return last modification time
int file_modification(char ** argv) {
	char buf[PATH_MAX];                  // These should be removed,
	char *pa = realpath(argv[1], buf);   // same data exists in main.
	struct stat st;
	if (stat(buf, &st)) {
		perror(buf);
	} else {
		char date[64];
		strftime(date, sizeof(date), "%c", localtime(&(st.st_ctime)));
		printf("File last modified:%4s%s\n", "", date);
	}
	return 0;
}

// todo
int whole_file(void) {
	printf("\nPrint all lines option (10 or less).\n");
	return 0;
}

// todo
int partial_file(int *nn) {
	printf("\nPrint trailing lines, it has %d lines total.\n", *nn);
	return 0;
}
