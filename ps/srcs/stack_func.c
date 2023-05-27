/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:46:51 by ubuntu            #+#    #+#             */
/*   Updated: 2023/05/28 06:17:43 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static t_node	*cr_node(int val[])
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->val[NUM] = val[NUM];
	new->val[ORDER] = val[ORDER];
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	push_head(t_stack *st, int val[])
{
	t_node	*temp;

	temp = cr_node(val);
	if (!st->size)
	{
		st->head = temp;
		st->tail = temp;
	}
	else
	{
		temp->next = st->head;
		st->head->prev = temp;
		st->head = temp;
	}
	st->size += 1;
}

void	push_tail(t_stack *st, int val[])
{
	t_node	*temp;

	temp = cr_node(val);
	if (!st->tail)
	{
		st->tail = temp;
		if (!(st->head))
			st->head = st->tail;
		else
		{
			st->head->next = st->tail;
			st->tail->prev = st->head;
		}
	}
	else
	{
		st->tail->next = temp;
		temp->prev = st->tail;
		st->tail = temp;
	}
	st->size += 1;
}

int	*pop_head(t_stack *st)
{
	static int	out[2];
	t_node		*temp;

	out[NUM] = st->head->val[NUM];
	out[ORDER] = st->head->val[ORDER];
	temp = st->head->next;
	free(st->head);
	st->head = temp;
	st->size -= 1;
	return (&out[0]);
}

int	*pop_tail(t_stack *st)
{
	static int	out[2];
	t_node		*temp;

	out[NUM] = st->tail->val[NUM];
	out[ORDER] = st->tail->val[ORDER];
	temp = st->tail->prev;
	free(st->tail);
	st->tail = temp;
	st->tail->next = 0;
	st->size -= 1;
	return (&out[0]);
}
