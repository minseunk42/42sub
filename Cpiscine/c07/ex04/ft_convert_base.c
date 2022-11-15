/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:50:28 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/06 17:56:38 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base, int ibase);
int	set_bn2(char *base, int *bn);

int	set_bn(char *base, int *bn)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	while (base[i])
		i++;
	*bn = i;
	i = -1;
	while (base[++i])
	{
		temp = base[i];
		if (temp == '+' || temp == '-')
			return (1);
		j = i;
		while (base[++j])
		{
			if (temp == base[j])
				return (1);
		}
	}
	return (0);
}

int	get_digit(long long nb, int bn)
{
	int	i;

	i = 1;
	while (nb / bn > 0)
	{
		i++;
		nb /= bn;
	}
	return (i);
}

char	*ft_putnbr_base(long long nb, char *base, int obase)
{
	int		i;
	char	*arr;

	arr = (char *)malloc(sizeof(char) * get_digit(nb, obase) + 2);
	if (!arr)
		return (0);
	if (nb < 0)
	{
		nb = -nb;
		arr[0] = '-';
		i = get_digit(nb, obase) + 1;
	}
	else
		i = get_digit(nb, obase);
	arr[i--] = 0;
	while (nb / obase > 0)
	{
		arr[i--] = base[nb % obase];
		nb /= obase;
	}
	arr[i] = base[nb % obase];
	return (arr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	i_num;
	int			ibase;
	int			obase;

	if (set_bn(base_to, &obase) || obase == 1 || !obase)
		return (0);
	if (set_bn2(base_from, &ibase) || ibase == 1 || !ibase)
		return (0);
	i_num = ft_atoi_base(nbr, base_from, ibase);
	return (ft_putnbr_base(i_num, base_to, obase));
}
