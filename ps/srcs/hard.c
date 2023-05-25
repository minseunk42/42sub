/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:06:21 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/25 18:55:19 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

char	*hard_three(t_stack st_arr[], int max)
{
	char	*out;

	out = 0;
	if (st_arr[STA].head->val[ORDER] == max - 2)
	{
		if (st_arr[STA].head->next->val[ORDER] == max)
			out = ft_strjoin(0, "sa\nra\n");
	}
	if (st_arr[STA].head->val[ORDER] == max - 1)
	{
		if (st_arr[STA].head->next->val[ORDER] == max - 2)
			out = ft_strjoin(0, "sa\n");
		else
			out = ft_strjoin(0, "rra\n");
	}
	if (st_arr[STA].head->val[ORDER] == max)
	{
		if (st_arr[STA].head->next->val[ORDER] == max - 2)
			out = ft_strjoin(0, "ra\n");
		else
			out = ft_strjoin(0, "sa\nrra\n");
	}
	return (out);
}

char	*hard_four(t_stack st_arr[], int max)
{
	char	*out;
	char	*temp;

	out = 0;
	while (st_arr[STA].head->val[ORDER] != 0)
	{
		proc_cmd("ra\n", st_arr);
		out = ft_strjoin(out, "ra\n");
	}
	out = ft_strjoin(out, "pb\n");
	proc_cmd("pb\n", st_arr);
	temp = hard_three(st_arr, max);
	out = ft_strjoin(out, temp);
	if (temp)
		free(temp);
	out = ft_strjoin(out, "pa\n");
	return (out);
}

char	*hard_five(t_stack st_arr[], int max)
{
	char	*out;
	char	*temp;

	out = 0;
	while (st_arr[STA].head->val[ORDER] != 0)
	{
		proc_cmd("ra\n", st_arr);
		out = ft_strjoin(out, "ra\n");
	}
	out = ft_strjoin(out, "pb\n");
	proc_cmd("pb\n", st_arr);
	while (st_arr[STA].head->val[ORDER] != 1)
	{
		proc_cmd("ra\n", st_arr);
		out = ft_strjoin(out, "ra\n");
	}
	out = ft_strjoin(out, "pb\n");
	proc_cmd("pb\n", st_arr);
	temp = hard_three(st_arr, max);
	out = ft_strjoin(out, temp);
	if (temp)
		free(temp);
	out = ft_strjoin(out, "pa\npa\n");
	return (out);
}

char	*hard(char *answer, t_stack st_arr[])
{
	t_stack *temp;

	temp = (t_stack *)ft_calloc(sizeof(t_stack), 3);
	ft_memcpy(temp, st_arr, 3 * sizeof(t_stack));
	if (get_stsize(st_arr[STA]) == 2)
		answer = ft_strjoin(answer, "sa\n");
	if (get_stsize(st_arr[STA]) == 3)
		answer = hard_three(temp, 2);
	if (get_stsize(st_arr[STA]) == 4)
		answer = hard_four(temp, 3);
	if (get_stsize(st_arr[STA]) == 5)
		answer = hard_five(temp, 4);
	free(temp);
	return (answer);
}
