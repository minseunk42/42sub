/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:37:03 by ubuntu            #+#    #+#             */
/*   Updated: 2023/05/19 20:06:02 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int puterr(void)
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

int	is_sorted(t_stack st_arr[])
{
	t_node	*temp;
	int		i;
	
	temp = st_arr[SA].head;
	i = 0;
	if (!st_arr[SB].head)
		return (-1);
	while (temp)
	{
		if (i++ != temp->order)
			return (-1);
		temp = temp->next;
	}
	return (0);
}