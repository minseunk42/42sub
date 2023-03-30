#include "ft_printf.h"

int	putchar_proc_error(char c)
{
	int	flag;

	flag = write(1, &c, 1);
	if (flag == -1)
		return (-1);
	return (0);
}

int	print_widt(t_format form)
{
	int	i;
	int flag;
	
	i = 0;
	while (++i < form.widt)
	{
		if (form.flag & ZRO)
			flag = putchar_proc_error('0');
		else
			flag = putchar_proc_error(' ');
		if (flag == -1)
			return (-1);
	}
	return (0);
}