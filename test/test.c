#include <stdio.h>
#include "ft_printf.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	val;
	int	sign;
	int	i;

	val = 0;
	i = 0;
	sign = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || ((str[i] == '-') && ++i && sign-- && sign--))
		i++;
	while (ft_isdigit(str[i]))
		val = 10 * val + (str[i++] - '0');
	return (sign * val);
}

int	is_type(char c)
{
	char	*str;
	int		i;

	i = -1;
	str = "cspdiuxX%";
	while (str[++i])
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

int	set_type(char c)
{
	if (c == 'c')
		return (CHR);
	if (c == 's')
		return (STR);
	if (c == 'p')
		return (PTR);
	if (c == 'd' || c == 'i')
		return (INT);
	if (c == 'u')
		return (USI);
	if (c == 'x' || c == 'X')
		return (HEX);
	if (c == '%')
		return (PCT);
	return (-1);
}

int	set_flag(char c)
{
	if (c == '-')
		return (MNS);
	if (c == '+')
		return (PLS);
	if (c == ' ')
		return (SPC);
	if (c == '0')
		return (ZRO);
	if (c == '#')
		return (SHP);
	return (0);
}

void init_form(t_format *form)
{
	form->widt = -1;
	form->flag = 0;
	form->prec = -1;
	form->type = -1;
}

void	set_format(char **str, t_format *form)
{
	init_form(form);
	while (form->type && **str)
	{
		form->flag |= set_flag(**str);
		if (**str >= '1' && **str <= '9')
		{
			form->widt = ft_atoi(*str);
			while (**str >= '0' && **str <= '9')
				(*str)++;
			continue;
		}
		if (**str == '.' && (*str)++)
		{	
			if (**str >= '0' && **str <= '9')
				form->prec = ft_atoi(*str);
			while (**str >= '0' && **str <= '9')
				(*str)++;
			continue;
		}
		if (is_type(**str))
			form->type = set_type(*(*str)++);
		else
			(*str)++;
	}
}

int main(int ac, char **av)
{
    t_format form;
	char *temp;
    if (ac < 2)
        return (0);
    
	temp = av[1];
	set_format(&av[1], &form);
	printf("type = %d\n",form.type);
    printf("widt = %d\n",form.widt);
    printf("prec = %d\n",form.prec);
    printf("flag = %d\n",form.flag);
	printf("!!%d!!\n",printf(temp,42));
}
