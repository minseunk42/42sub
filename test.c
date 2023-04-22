#include <stdio.h>

int ft_printf(char *str, ...);

int main()
{
	char *s = "hihi";
	printf("!\n%d\n",printf("%015x", 2));
	printf("!\n%d\n",ft_printf("%015x", 2));
}
