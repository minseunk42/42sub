/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:49:25 by minseunk          #+#    #+#             */
/*   Updated: 2022/12/15 19:20:07 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	my_atoi(char *str)
{
	int	i;
	int	sign;
	int	val;

	i = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	val = 0;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		val = val * 10 + (str[i] - '0');
		i++;
	}
	return (val * sign);
}

void	my_putnbr(int nb)
{
	long	nbl;
	char	na[10];
	int		i;

	nbl = nb;
	if (nbl < 0)
	{
		write(1, "-", 1);
		nbl = -nbl;
	}
	i = 0;
	while (nbl / 10 > 0)
	{
		na[i++] = '0' + (nbl % 10);
		nbl = nbl / 10;
	}
	na[i++] = '0' + (nbl % 10);
	while (i-- > 0)
		write(1, &(na[i]), 1);
	write(1, "\n", 1);
}

int	check_op(char *str, int *opn)
{
	if (*str == '+')
		*opn = ADD;
	if (*str == '-')
		*opn = SUB;
	if (*str == '*')
		*opn = MUL;
	if (*str == '/')
		*opn = DIV;
	if (*str == '%')
		*opn = MOD;
	str++;
	if (*opn < ADD || *opn > MOD || *str)
	{
		write (1, "0\n", 2);
		return (-1);
	}
	return (1);
}

int	check_2nd_av(char *str, int opn)
{
	if (!my_atoi(str) && (opn == DIV || opn == MOD))
	{
		if (opn == DIV)
			write(1, "Stop : division by zero\n", 24);
		if (opn == MOD)
			write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	(*fp[5])(int, int);
	int	opn;

	if (ac != 4)
		return (-1);
	if (check_op(av[2], &opn) < 0)
		return (-1);
	if (!check_2nd_av(av[3], opn))
		return (-1);
	fp[ADD] = add;
	fp[SUB] = sub;
	fp[MUL] = mul;
	fp[DIV] = div;
	fp[MOD] = mod;
	my_putnbr(fp[opn](my_atoi(av[1]), my_atoi(av[3])));
}
