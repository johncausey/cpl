/*
	Program to read a file
	and count newlines, tabs,
	and spaces.
*/

#include <stdio.h>

main()
{
	FILE *ff; /* Setting file */
	int c, tb, bl, nl; /* Setting int */
	tb = bl = nl = 0; /* Values should equal 0 before while statement - counter values */

	ff = fopen("contentfile.txt", "r"); /* Read file */
	if (ff) {
		while ((c = getc(ff)) != EOF) {
			/*  */
			if (c == '\t')
				++tb;
			if (c == ' ')
				++bl;
			if (c == '\n')
				++nl;
			putchar(c);
		}
		fclose(ff);
		printf("There are %d tabs, %d blanks, and %d newlines in file.\n", tb, bl, nl);
	}
	if (!ff) {
		printf("Unable to open file\n");
		return 1;
	}
}
