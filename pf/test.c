#include <stdio.h>

int main()
{
	int a = 0b010;
	printf("%d", (a & 2) && (a & ~1) && (a & ~4));
}
