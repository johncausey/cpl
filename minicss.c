// Program to minify CSS files, leaves license info.

#include <stdio.h>

#define IN 1        // Inside bool.
#define OUT 0       // Outside bool.

void main( int argc, char ** argv ) {
	
	FILE * fr = fopen(argv[1], "r");
	FILE * fw = fopen("minified.css", "w");
	int c, pc = 0;
	int comment_e = OUT;
	int space_e = OUT;
	int license_e = IN;

	if (fr) {
		while ((c = getc(fr)) != EOF ) {
			
			// Pass once to leave formatting of license comment.
			if (license_e == IN) {
				if ((c == '*') && (pc == '/')) {
					comment_e = IN;
				} else if ((c == '/') && (pc == '*')) {
					comment_e = OUT;
					putc('/', fw);
					putc('\n', fw);
					putc('\n', fw);
					license_e = OUT;
					continue;
				}
				// Write inside comment.
				if (comment_e == IN) {
					putc(c, fw);
					pc = c;
					continue;
				}
			}

			// Write all outside license CSS, skipping newlines and tabs.
			if ((c != '\n') && (c != '\t')) {
				if (comment_e == OUT) {
					// Allow only one space.
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
		printf("Minification complete at 'minified.css'.\n");
		fclose(fr);
		fclose(fw);
	}
	else {
		printf("File not found.");
	}
}
