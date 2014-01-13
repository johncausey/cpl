// Program to minify CSS files.

#include <stdio.h>

#define INSPACE 1    // Inside a space grouping.
#define OUTSPACE 0   // Outside a space grouping.

void main( int argc, char ** argv ) {
	
	FILE * fr = fopen(argv[1], "r");
	FILE * fw = fopen("minified.css", "w");
	int c, i = 0;
	int space_s = OUTSPACE;

	if (fr) {
		while ((c = getc(fr)) != EOF ) {
			if ((c != '\n') && (c != '\t')) {
				if ((c == ' ') && (space_s == OUTSPACE)) {
					putc(c, fw);
					space_s = INSPACE;
				} else if ((c == ' ') && (space_s == INSPACE)) {
					;
				} else if (c != ' ') {
					space_s = OUTSPACE;
					putc(c, fw);
				}
			}
		}
		printf("Minification Complete.\n");
		fclose(fr);
		fclose(fw);
	}
	else {
		printf("File not found.");
	}
}
