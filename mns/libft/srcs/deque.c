/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:56:21 by gylim             #+#    #+#             */
/*   Updated: 2023/06/26 20:53:51 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "deque.h"
#include "deque_backend.h"

int	dq_add_front(t_deque dq, t_item item)
{
	if (dq == NULL)
		return (-1);
	return (add_node_to_front(dq, new_node(item)));
}

int	dq_add_rear(t_deque dq, t_item item)
{
	if (dq == NULL)
		return (-1);
	return (add_node_to_rear(dq, new_node(item)));
}

int	dq_delete_front(t_deque dq)
{
	struct s_node	*predecessor;

	if (dq == NULL)
		return (-1);
	if (dq->size == 0)
		return (0);
	predecessor = dq->front;
	dq->front = predecessor->next;
	if (dq->front != NULL)
		dq->front->prev = NULL;
	free(predecessor);
	dq->size--;
	return (0);
}

int	dq_delete_rear(t_deque dq)
{
	struct s_node	*predecessor;

	if (dq == NULL)
		return (-1);
	if (dq->size == 0)
		return (0);
	predecessor = dq->rear;
	dq->rear = predecessor->prev;
	if (dq->rear != NULL)
		dq->rear->next = NULL;
	free(predecessor);
	dq->size--;
	return (0);
}

int	dq_destroy(t_deque dq)
{
	if (dq == NULL)
		return (0);
	while (dq->front != NULL)
		dq_delete_front(dq);
	free(dq);
	return (0);
}
