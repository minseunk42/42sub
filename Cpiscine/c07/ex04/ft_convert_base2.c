/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:41:28 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/06 13:17:50 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	set_bn2(char *base, int *bn)
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
		if (temp == '+' || temp == '-' )
			return (1);
		if (temp == ' ' || (9 <= temp && temp <= 13))
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

int	get_base(char str, char *base, int bn)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == str)
			break ;
		i++;
	}
	if (i == bn)
		return (-1);
	else
		return (i);
}

int	ft_atoi_base(char *str, char *base, int ibase)
{
	int	i;
	int	val;
	int	sign;

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
	while (get_base(str[i], base, ibase) >= 0)
	{
		val = val * ibase + get_base(str[i], base, ibase);
		i++;
	}
	return (val * sign);
}
