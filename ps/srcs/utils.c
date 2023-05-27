/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:37:03 by ubuntu            #+#    #+#             */
/*   Updated: 2023/05/28 06:10:00 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	puterr(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

long long	ft_atol(const char *str)
{
	long long	val;
	int			sign;
	int			i;

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

int	has_spa(char *str)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (str[++i])
	{
		if (str[i] == ' ')
		{
			flag = 1;
			if (str[i + 1] == ' ')
				return (-1);
		}
	}
	return (flag);
}

int	is_sorted(t_stack st_arr[])
{
	t_node	*temp;
	int		i;

	temp = st_arr[STA].head;
	i = 0;
	if (st_arr[STB].head)
		return (0);
	while (temp)
	{
		if (i++ != temp->val[ORDER])
			return (0);
		temp = temp->next;
	}
	return (1);
}
