// Program to minify CSS files.

#include <stdio.h>

void main( int argc, char ** argv ) {
	
	FILE * fr = fopen(argv[1], "r");
	FILE * fw = fopen("minified.css", "w");
	int c;
	int i = 0;

	if (fr) {
		while ((c = getc(fr)) != EOF ) {
			if ((c != '\n') && (c != '\t')) {
				putc(c, fw);
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
