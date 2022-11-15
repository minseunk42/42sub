/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:44:18 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/03 15:57:46 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putnbr_base(int nbr, char *base)
{
	int			i;
	int			bn;
	int			arr[32];
	long long	nbl;

	if (set_bn(base, &bn) || bn == 1 || !bn)
		return ;
	i = 0;
	nbl = nbr;
	if (nbl < 0)
	{
		write(1, "-", 1);
		nbl = -nbl;
	}
	while (nbl / bn > 0)
	{
		arr[i++] = nbl % bn;
		nbl /= bn;
	}
	arr[i] = nbl % bn;
	while (i >= 0)
		write(1, &base[arr[i--]], 1);
}
