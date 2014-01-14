// Program to minify CSS files.

#include <stdio.h>

#define IN 1        // Inside element.
#define OUT 0       // Outside element.

void main( int argc, char ** argv ) {
	
	FILE * fr = fopen(argv[1], "r");
	FILE * fw = fopen("minified.css", "w");
	int c, pc = 0;
	int comment_e = OUT;
	int space_e = OUT;

	if (fr) {
		while ((c = getc(fr)) != EOF ) {
			if ((c != '\n') && (c != '\t')) {

				if ((c == '*') && (pc == '/')) {
					comment_e = IN;
				} else if ((c == '/') && (pc == '*')) {
					comment_e = OUT;
				}

				if (comment_e == OUT) {
					if (c == ' ' && space_e == OUT) {
						putc(c, fw);
						space_e = IN;
					} else if (c != ' ') {
						putc(c, fw);
						space_e = OUT;
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
