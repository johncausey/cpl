// Program to minify CSS files.

#include <stdio.h>

void main( int argc, char ** argv ) {
	
	FILE * fr = fopen(argv[1], "r");
	FILE * fw = fopen("minified.css", "w");
	int c;
	int i = 0;
	char mintag[] = "\n\nMinified by John Causey.";

	if (fr) {
		while ((c = getc(fr)) != EOF ) {
			if ()
			putc(c, fw);
		}
		fputs(mintag, fw);
		printf("Minification Complete.\n");
		fclose(fr);
		fclose(fw);
	}
}
