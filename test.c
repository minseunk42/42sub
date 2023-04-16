#include <stdio.h>

int ft_printf(char *str, ...);

int main()
{
	printf("%d\n",printf(" %.2s %.3s %.4s %.5s %.1s ", " - ", "", "4", "", "2 "));
	printf("%d\n",ft_printf(" %.2s %.3s %.4s %.5s %.1s ", " - ", "", "4", "", "2 "));
}
