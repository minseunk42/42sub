/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:05:51 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/26 16:39:56 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	get_maxidx(t_stack st_arr[])
{
	t_node	*temp;
	int		i;

	temp = st_arr[STB].head;
	i = 0;
	while (temp->val[ORDER] != st_arr[STB].size - 1)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

char	*btoa(char *answer, t_stack st_arr[])
{
	while (st_arr[STB].size)
	{
	
		if (st_arr[STB].size / 2 > get_maxidx(st_arr))
		{
			while (st_arr[STB].head->val[ORDER] != st_arr[STB].size -1)
			{
				answer = ft_strjoin(answer, CRB);
				proc_cmd(CRB, st_arr);
			}
		}
		else
		{
			while (st_arr[STB].head->val[ORDER] != st_arr[STB].size -1)
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

char	*atob(char *answer, t_stack st_arr[], int chunk)
{
	int	i;

	i = 0;
	while (st_arr[STA].size)
	{
		if (st_arr[STA].head->val[ORDER] <= i)
		{
			i++;
			answer = ft_strjoin(answer, CPB);
			proc_cmd(CPB, st_arr);
		}
		else if (st_arr[STA].head->val[ORDER] < i + chunk)
		{
			i++;
			answer = ft_strjoin(answer, CPB);
			answer = ft_strjoin(answer, CRB);
			proc_cmd(CPB, st_arr);
			proc_cmd(CRB, st_arr);
		}
		else
		{
			answer = ft_strjoin(answer, CRA);
			proc_cmd(CRA, st_arr);
		}
	}
	return (answer);
}

char	*algo(char *answer, t_stack st_arr[])
{
	t_stack *temp;

	temp = (t_stack *)ft_calloc(sizeof(t_stack), 3);
	ft_memcpy(temp, st_arr, 3 * sizeof(t_stack));
	answer = atob(answer, temp, (st_arr[STA].size / 100) * 5 + 7);
	answer = btoa(answer, temp);
	free(temp);
	return (answer);
}

int	main(int ac, char **av)
{
	t_stack	st_arr[2];
	char	*answer;

	if (ac < 2)
		return (-1);
	init(st_arr);
	if (proc_av(av, st_arr) && puterr())
		return (-1);
	if (is_sorted(st_arr))
		return (0);
	answer = 0;
	if (st_arr[STA].size < 6)
		answer = hard(answer, st_arr);
	else
		answer = algo(answer, st_arr);
	ft_printf(answer);
	free(answer);
	return (0);
}
