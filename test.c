#include <stdio.h>

int ft_printf(char *str, ...);

int main()
{
	printf("%d\n",printf("%32s", NULL));
	printf("%d\n",ft_printf("%32s", NULL));
}
