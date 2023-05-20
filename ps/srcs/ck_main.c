/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:05:51 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/19 20:28:01 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	set_av(t_stack st_arr[], int arg)
{
	t_node	*temp;
	int		i;
	
	i = 0;
	temp = st_arr[SA].head;
	while (temp)
    {
        if (temp->value == arg)
            return (-1);
		if (temp->value > arg)
			temp->order += 1;
		else
			i++;
        temp = temp->next;
    }
    push_head(&(st_arr[SA]), arg);
	st_arr[SA].head->order = i;
    return (0);
}

int check_av(char *str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        if (ft_atol(str) > INTMAX || ft_atol(str) < INTMIN)
            return (-1);
        if (!(ft_isdigit(str[i]) || str[i] == '-'))
            return (-1);
        if (str[i] == '-' && !(ft_isdigit(str[i + 1])))
            return (-1);
	}
	if (i == 0)
		return (-1);
    return (0);
}

int putav(char **av, t_stack st_arr[])
{
    int		i;
	
    i = 0;
    while (av[++i])
    {
        if (check_av(av[i]) && free_sta(st_arr))
            return (-1);
    }
	return (0);
}

void	init(t_stack st_arr[])
{
	st_arr[SA].head = NULL;
	st_arr[SA].tail = NULL;
	st_arr[SB].head = NULL;
	st_arr[SB].tail = NULL;
}

int	main(int ac, char **av)
{
    t_stack st_arr[2];
    t_node *temp;

	init(st_arr);
    if ((ac < 2 || putav(av, st_arr)) && puterr())
        return (-1);
    temp = st_arr[SA].head;
	while (temp)
	{
		ft_printf("%d  %d\n", temp->value, temp->order);
		temp = temp->next;
	}
}
