/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:54:24 by minseunk          #+#    #+#             */
/*   Updated: 2023/06/14 18:57:02 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	set_sa(t_stack st_arr[], int arg)
{
	t_node	*temp;
	int		i;
	int		val[2];

	i = 0;
	temp = st_arr[STA].head;
	while (temp)
	{
		if (temp->val[NUM] == arg)
			return (-1);
		if (temp->val[NUM] > arg)
			temp->val[ORDER] += 1;
		else
			i++;
		temp = temp->next;
	}
	val[NUM] = arg;
	val[ORDER] = i;
	push_tail(&(st_arr[STA]), val);
	free(temp);
	return (EXIT_SUCCESS);
}

int	set_str(char *str, t_stack st_arr[])
{
	int	i;

	i = -1;
	if (ft_atol(str) > INTMAX || ft_atol(str) < INTMIN)
		return (-1);
	while (str[++i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+'))
			return (-1);
		if (str[i] == '-' && !(ft_isdigit(str[i + 1])))
			return (-1);
		if (str[i] == '+' && !(ft_isdigit(str[i + 1])))
			return (-1);
	}
	if (i == 0 || i > 11)
		return (-1);
	if (set_sa(st_arr, ft_atol(str)))
		return (-1);
	return (0);
}

int	proc_av(char **av, t_stack st_arr[])
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	temp = 0;
	while (av[++i])
	{
		if (has_spa(av[i]))
		{
			temp = ft_split(av[i], ' ');
			j = -1;
			while (temp[++j])
			{
				if (set_str(temp[j], st_arr))
					return (free_all(temp, st_arr, 0));
			}
		}
		else if (set_str(av[i], st_arr))
			return (free_all(temp, st_arr, 0));
	}
	if (temp)
		free_strs(temp);
	return (EXIT_SUCCESS);
}

void	init_st(t_stack st_arr[])
{
	st_arr[STA].head = NULL;
	st_arr[STA].tail = NULL;
	st_arr[STA].size = 0;
	st_arr[STB].head = NULL;
	st_arr[STB].tail = NULL;
	st_arr[STB].size = 0;
}
