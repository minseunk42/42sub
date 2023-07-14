/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:09:15 by gylim             #+#    #+#             */
/*   Updated: 2023/06/26 17:29:17 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "deque.h"
#include "deque_backend.h"

/* precondition: dq->size > 0 == true */
t_item	dq_front(t_deque dq)
{
	return (dq->front->item);
}

/* precondition: dq->size > 0 == true */
t_item	dq_rear(t_deque dq)
{
	return (dq->rear->item);
}

t_deque	dq_new(void)
{
	t_deque	dq;

	dq = (t_deque)malloc(sizeof(struct s_deque));
	if (dq == NULL)
		return (NULL);
	dq->front = NULL;
	dq->rear = NULL;
	dq->size = 0;
	return (dq);
}

int	dq_size(t_deque dq)
{
	if (dq == NULL)
		return (-1);
	return (dq->size);
}
