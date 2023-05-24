/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:46:51 by ubuntu            #+#    #+#             */
/*   Updated: 2023/05/23 16:59:07 by minseunk         ###   ########.fr       */
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
	return (new);
}

void	push_head(t_stack *st, int val[])
{
	t_node	*temp;

	temp = cr_node(val);
	if (!st->head)
	{
		st->head = temp;
		st->head->next = (*st).tail;
	}
	else
	{
		st->head->prev = temp;
		temp->next = st->head;
		st->head = temp;
	}
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
	st->tail->next = NULL;
	return (&out[0]);
}
