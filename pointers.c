
#include <stdio.h>
#include <stdlib.h>

void change_value(int*);

int main() {
	int n = 10;

	printf("The value of n is %d\n", n);
	change_value(&n);
	printf("The value of n is %d\n", n);

	return 0;
}

void change_value(int *p) {
	*p = 15;
}
