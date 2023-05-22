/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:46:51 by ubuntu            #+#    #+#             */
/*   Updated: 2023/05/22 12:02:38 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static t_node	*cr_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	push_head(t_stack *st, int value)
{
	t_node	*temp;

	temp = cr_node(value);
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

void	push_tail(t_stack *st, int value)
{
	t_node	*temp;

	temp = cr_node(value);
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

int	pop_head(t_stack *st)
{
	int		out;
	t_node	*temp;

	out = st->head->value;
	temp = st->head->next;
	free(st->head);
	st->head = temp;
	return (out);
}

int	pop_tail(t_stack *st)
{
	int		out;
	t_node	*temp;

	out = st->tail->value;
	temp = st->tail->prev;
	free(st->tail);
	st->tail = temp;
	st->tail->next = NULL;
	return (out);
}
