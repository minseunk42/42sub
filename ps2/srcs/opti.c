/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:09:22 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/26 20:26:51 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

char	*ratorra(int i, int j, char *answer, int rracnt)
{
	int		k;
	char	*out;
	char	*temp;

	out = 0;
	temp = ft_substr(answer, 0, i);
	out = ft_strjoin(out, temp);
	free(temp);
	k = -1;
	while (++k < rracnt)
		out = ft_strjoin(out, CRRA);
	temp = ft_substr(answer, j, ft_strlen(answer) - j);
	out = ft_strjoin(out, temp);
	free(temp);
	free(answer);
	return (out);
}

char	*opti_ra(char *answer, t_stack st_arr[])
{
	int		i;
	int		j;
	int		cnt;

	i = -1;
	while (answer[++i])
	{
		cnt = 0;
		j = i;
		while (!ft_strncmp(&answer[j], CRA, 3) && ++cnt)
			j += 3;
		if (cnt > st_arr[STA].size / 2)
		{
			answer = ratorra(i, j, answer, (st_arr[STA].size - cnt));
			j = i + (4 * (st_arr[STA].size - cnt));
			i = j;
		}
		if (!ft_strncmp(&answer[i], CPB, 3))
			st_arr[STA].size -= 1;
	}
	return (answer);
}

char	*opti(char *answer, t_stack st_arr[])
{
	t_stack *temp;

	temp = (t_stack *)ft_calloc(sizeof(t_stack), 3);
	ft_memcpy(temp, st_arr, 3 * sizeof(t_stack));
	answer = opti_ra(answer, temp);
	free(temp);
	return (answer);
}