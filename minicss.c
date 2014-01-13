// Program to minify CSS files.

#include <stdio.h>

#define INSPACE 1      // Inside space.
#define OUTSPACE 0     // Outside space.
#define INCOMMENT 1    // Inside comment.
#define OUTCOMMENT 0   // Outside comment.
#define INURL 1        // Inside URL.
#define OUTURL 0       // Outside URL.

void main( int argc, char ** argv ) {
	
	FILE * fr = fopen(argv[1], "r");
	FILE * fw = fopen("minified.css", "w");
	int c, pc = 2;
	int space_s = OUTSPACE;
	int comment_s = OUTCOMMENT;
	int url_s = OUTURL;

	if (fr) {
		while ((c = getc(fr)) != EOF ) {
			if ((c != '\n') && (c != '\t')) {

				// Designate URL avoidance
				if (c == '(') {
					url_s = INURL;
				} else if (c == ')') {
					url_s = OUTURL;
				}

				// Remove excess spaces
				if ((c == ' ') && (space_s == OUTSPACE)) {
					putc(c, fw);
					space_s = INSPACE;
				} else if ((c == ' ') && (space_s == INSPACE)) {
					;
				} else if ((c != ' ') && (comment_s == OUTCOMMENT)) {
					space_s = OUTSPACE;
					putc(c, fw);
				}

				// Remove all comments
				if ((c == '/') && (url_s == OUTURL)) {
					comment_s = INCOMMENT;
				}
				if (comment_s == INCOMMENT) {
					if ((c == '/') && (pc == '*')) {
						comment_s = OUTCOMMENT;
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
