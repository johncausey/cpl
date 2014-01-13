// Program to minify CSS files.

#include <stdio.h>

#define IN 1        // Inside element.
#define OUT 0       // Outside element.


void main( int argc, char ** argv ) {
	
	FILE * fr = fopen(argv[1], "r");
	FILE * fw = fopen("minified.css", "w");
	int c, pc = 2;
	int space_s = OUT;
	int comment_s = OUT;
	int url_s = OUT;

	if (fr) {
		while ((c = getc(fr)) != EOF ) {
			if ((c != '\n') && (c != '\t')) {

				// Designate URL avoidance
				if (c == '(') {
					url_s = IN;
				} else if (c == ')') {
					url_s = OUT;
				}

				// Remove excess spaces
				if ((c == ' ') && (space_s == OUT)) {
					putc(c, fw);
					space_s = IN;
				} else if ((c == ' ') && (space_s == IN)) {
					;
				} else if ((c != ' ') && (comment_s == OUT)) {
					space_s = OUT;
					putc(c, fw);
				}

				// Remove all comments
				if ((c == '/') && (url_s == OUT)) {
					comment_s = IN;
				}
				if (comment_s == IN) {
					if ((c == '/') && (pc == '*')) {
						comment_s = OUT;
					}
				}

				// Set last int c to pc
				pc = c;
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
