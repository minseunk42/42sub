/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:18:57 by minseunk          #+#    #+#             */
/*   Updated: 2023/06/14 18:56:30 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	is_close_top(t_stack st_arr[])
{
	t_node	*temp;
	int		i;

	temp = st_arr[STB].head;
	i = 0;
	while (temp->val[ORDER] != st_arr[STB].size - 1)
	{
		temp = temp->next;
		i++;
		if (i > st_arr[STB].size / 2)
			return (0);
	}
	return (1);
}

char	*btoa(char *answer, t_stack st_arr[])
{
	while (st_arr[STB].size)
	{
		if (is_close_top(st_arr))
		{
			while (st_arr[STB].head->val[ORDER] != st_arr[STB].size - 1)
			{
				answer = ft_strjoin(answer, CRB);
				proc_cmd(CRB, st_arr);
			}
		}
		else
		{
			while (st_arr[STB].head->val[ORDER] != st_arr[STB].size - 1)
			{
				answer = ft_strjoin(answer, CRRB);
				proc_cmd(CRRB, st_arr);
			}
		}
		answer = ft_strjoin(answer, CPA);
		proc_cmd(CPA, st_arr);
	}
	return (answer);
}

char	*atob(char *answer, t_stack st_arr[])
{
	int	i;
	int	chunk;

	i = 0;
	while (st_arr[STA].size)
	{
		chunk = (st_arr[STA].size / 10) + 5;
		if (st_arr[STA].head->val[ORDER] <= i && ++i)
		{
			answer = ft_strjoin(answer, CPB);
			proc_cmd(CPB, st_arr);
		}
		else if (st_arr[STA].head->val[ORDER] < i + chunk && ++i)
		{
			answer = ft_strjoin(answer, CPB);
			answer = ft_strjoin(answer, CRB);
			proc_cmd(CPB, st_arr);
			proc_cmd(CRB, st_arr);
		}
		else if (!proc_cmd(CRA, st_arr))
			answer = ft_strjoin(answer, CRA);
	}
	return (answer);
}

char	*algo(char *answer, t_stack st_arr[])
{
	t_stack	temp[2];
	t_stack	temp2[2];

	copy_st(st_arr, temp);
	copy_st(st_arr, temp2);
	answer = atob(answer, temp);
	answer = opti(answer, temp2);
	answer = btoa(answer, temp);
	free_sta(temp);
	free_sta(temp2);
	return (answer);
}
