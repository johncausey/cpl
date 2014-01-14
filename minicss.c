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
	int license_e = IN;

	if (fr) {
		while ((c = getc(fr)) != EOF ) {
			
			if (license_e == IN) {
				if ((c == '*') && (pc == '/')) {
					comment_e = IN;
				} else if ((c == '/') && (pc == '*')) {
					comment_e = OUT;
					putc('/', fw);
					putc('\n', fw);
					license_e = OUT;
					continue;
				}
				if (comment_e == IN) {
					putc(c, fw);
					pc = c;
					continue;
				}
			}

			if ((c != '\n') && (c != '\t')) {
				if (comment_e == OUT) {
					if (c == ' ' && space_e == OUT) {
						putc(c, fw);
						space_e = IN;
					} else if (c != ' ') {
						putc(c, fw);
						space_e = OUT;
					}
				}
			}
			pc = c;
		}
		printf("Minification Complete.\n");
		fclose(fr);
		fclose(fw);
	}
	else {
		printf("File not found.");
	}
}
