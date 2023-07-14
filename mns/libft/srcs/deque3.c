/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:23:10 by gylim             #+#    #+#             */
/*   Updated: 2023/06/26 17:29:34 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "deque.h"
#include "deque_backend.h"

/*return value: (loc > 0) of node containing key
 *				-1 if there's no node containing key
 */
int	dq_search(t_deque dq, t_item key)
{
	struct s_node	*cur;
	int				i;

	if (dq == NULL)
		return (-1);
	i = 0;
	cur = dq->front;
	while (cur)
	{
		if (cur->item == key)
			return (i);
		cur = cur->next;
		i++;
	}
	return (-1);
}

/* precondition: dq != NULL */
int	dq_empty(t_deque dq)
{
	return (dq->size == 0);
}
