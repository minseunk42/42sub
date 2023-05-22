/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:25:19 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/22 11:57:35 by minseunk         ###   ########.fr       */
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
	clear_stack(&(st_arr[SA]));
	clear_stack(&(st_arr[SB]));
	return (1);
}
