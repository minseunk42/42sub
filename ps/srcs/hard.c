/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:06:21 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/23 22:01:19 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

char	*hard_three(t_stack st_arr[], int max)
{
	char	*out;

	out = "";
	if (st_arr[SA].head->val[ORDER] == max - 2)
	{
		if (st_arr[SA].head->next->val[ORDER] == max)
			out = ft_strjoin(0, "sa\nra\n");
	}
	if (st_arr[SA].head->val[ORDER] == max - 1)
	{
		if (st_arr[SA].head->next->val[ORDER] == max - 2)
			out = ft_strjoin(0, "sa\n");
		else
			out = ft_strjoin(0, "rra\n");
	}
	if (st_arr[SA].head->val[ORDER] == max)
	{
		if (st_arr[SA].head->next->val[ORDER] == max - 2)
			out = ft_strjoin(0, "ra\n");
		else
			out = ft_strjoin(0, "sa\nrra\n");
	}
	return (out);
}

char	*hard_four(t_stack st_arr[], int max)
{
	char	*out;
	
	out = 0;
	while (st_arr[SA].head->val[ORDER] != 0)
	{
		proc_cmd("ra\n", st_arr);
		out = ft_strjoin(out, "ra\n");
	}
	out = ft_strjoin(out, "pb\n");
	proc_cmd("pb\n", st_arr);
	out = ft_strjoin(out, hard_three(st_arr, max));
	out = ft_strjoin(out, "pa\n");
	return (out);
}

char	*hard_five(t_stack st_arr[], int max)
{
	char	*out;
	
	out = 0;
	while (st_arr[SA].head->val[ORDER] != 0)
	{
		proc_cmd("ra\n", st_arr);
		out = ft_strjoin(out, "ra\n");
	}
	out = ft_strjoin(out, "pb\n");
	proc_cmd("pb\n", st_arr);
	while (st_arr[SA].head->val[ORDER] != 1)
	{
		proc_cmd("ra\n", st_arr);
		out = ft_strjoin(out, "ra\n");
	}
	out = ft_strjoin(out, "pb\n");
	proc_cmd("pb\n", st_arr);
	out = ft_strjoin(out, hard_three(st_arr, max));
	out = ft_strjoin(out, "pa\n");
	out = ft_strjoin(out, "pa\n");
	return (out);
}

char	*hard_code(char *answer, t_stack st_arr[])
{
    if (get_stsize(st_arr[SA]) == 2)
		answer = ft_strjoin(answer, "sa\n");
	if (get_stsize(st_arr[SA]) == 3)
		answer = hard_three(st_arr, 2);
	if (get_stsize(st_arr[SA]) == 4)
		answer = hard_four(st_arr, 3);
	if (get_stsize(st_arr[SA]) == 5)
		answer = hard_five(st_arr, 4);
	return (answer);
}

