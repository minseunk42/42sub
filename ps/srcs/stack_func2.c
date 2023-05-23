/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:55:56 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/23 21:25:24 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int get_stsize(t_stack st)
{
    int i;
    
    i = 0;
    while (st.head)
    {
        i++;
        st.head = st.head->next;
    }
    return (i);
}

int	proc_cmd(char *cmd, t_stack st_arr[])
{
	if (!ft_strncmp(cmd, "pa\n", ft_strlen(cmd)))
		pa(st_arr);
	else if (!ft_strncmp(cmd, "pb\n", ft_strlen(cmd)))
		pb(st_arr);
	else if (!ft_strncmp(cmd, "ra\n", ft_strlen(cmd)))
		ra(st_arr);
	else if (!ft_strncmp(cmd, "rb\n", ft_strlen(cmd)))
		rb(st_arr);
	else if (!ft_strncmp(cmd, "rr\n", ft_strlen(cmd)))
		rr(st_arr);
	else if (!ft_strncmp(cmd, "rra\n", ft_strlen(cmd)))
		rra(st_arr);
	else if (!ft_strncmp(cmd, "rrb\n", ft_strlen(cmd)))
		rrb(st_arr);
	else if (!ft_strncmp(cmd, "rrr\n", ft_strlen(cmd)))
		rrr(st_arr);
	else if (!ft_strncmp(cmd, "sa\n", ft_strlen(cmd)))
		sa(st_arr);
	else if (!ft_strncmp(cmd, "sb\n", ft_strlen(cmd)))
		sb(st_arr);
	else if (!ft_strncmp(cmd, "ss\n", ft_strlen(cmd)))
		ss(st_arr);
	else
		return (-1);
	return (0);
}