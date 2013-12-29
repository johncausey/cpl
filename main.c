
#include <stdio.h>

main()
{
  FILE *ff;
  int c, tb, bl, nl;
  tb = bl = nl = 0;

  ff = fopen("contentfile.txt", "r");
  if (ff) {
	while ((c = getc(ff)) != EOF) {
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
