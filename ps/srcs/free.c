/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:25:19 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/24 19:35:34 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	clear_stack(t_stack *st)
{
	t_node	*temp;

	while (st->head)
	{
		temp = st->head->next;
		free(st->head);
		st->head = temp;
	}
	st->head = NULL;
	st->tail = NULL;
}

int	free_sta(t_stack st_arr[])
{
	clear_stack(&(st_arr[STA]));
	clear_stack(&(st_arr[STB]));
	return (1);
}

int free_strs(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
	{
		free(strs[i]);	
	}
	free(strs);
	return (1);
}

int	free_all(char **strs, t_stack st_arr[], char *cmd)
{
	if (strs)
		free_strs(strs);
	if (st_arr)	
		free_sta(st_arr);
	if (cmd)
		free(cmd);
	return (1);
}
