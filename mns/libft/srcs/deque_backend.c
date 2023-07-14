/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_backend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:38:13 by gylim             #+#    #+#             */
/*   Updated: 2023/06/20 21:45:11 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "deque.h"
#include "deque_backend.h"

struct s_node	*new_node(t_item item)
{
	struct s_node	*new_nd;

	new_nd = (struct s_node *)malloc(sizeof(struct s_node));
	if (new_nd == NULL)
		return (NULL);
	new_nd->prev = NULL;
	new_nd->next = NULL;
	new_nd->item = item;
	return (new_nd);
}

int	add_node_to_front(t_deque dq, struct s_node *nd)
{
	if (nd == NULL)
		return (-1);
	if (dq->size == 0)
	{
		dq->front = nd;
		dq->rear = nd;
	}
	else
	{
		dq->front->prev = nd;
		nd->next = dq->front;
		dq->front = nd;
	}
	dq->size++;
	return (0);
}

int	add_node_to_rear(t_deque dq, struct s_node *nd)
{
	if (nd == NULL)
		return (-1);
	if (dq->size == 0)
	{
		dq->front = nd;
		dq->rear = nd;
	}
	else
	{
		dq->rear->next = nd;
		nd->prev = dq->rear;
		dq->rear = nd;
	}
	dq->size++;
	return (0);
}
