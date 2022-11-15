/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:56:45 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/16 19:33:39 by kelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

t_list	*create_elem(char *key, char *val)
{
	t_list	*new_list;

	new_lis = malloc(sizeof(t_list));
	new_list->next = NULL;
	new_list->key = (char *)malloc(sizeof(char) * (_strlen_(key) + 1));
	_memcopy_(new_list->key, key, _strlen_(key) + 1);
	new_list->val = (char *)malloc(sizeof(char) * (_strlen_(val) + 1));
	_memcopy_(new_list->val, val, _strlen_(val) + 1);
	return (new_list);
}

void	add_list(t_list **dict, char *key, char *val)
{
	t_list	*new_n;
	t_list	*head;

	head = *dict;
	new_n = create_elem(key, val);
	new_n->next = head;
	*dict = new_n;
}

t_list	*sort_insertion_list(t_list *head)
{
	t_list	*new_list;
	t_list	*curr;
	t_list	*prev;
	t_list	*nextlist;

	new_list = create_elem("0", "0");
	prev = new_list;
	curr = head;
	while (curr)
	{
		nextlist = curr->next;
		if (_strcmp_(prev->key, curr->key) >= 0)
			prev = new_list;
		while (prev->next && order_tbl(prev->next->key, curr->key) < 0)
			prev = prev->next;
		curr->next = prev->next;
		prev->next = curr;
		curr = nextlist;
	}
	return (new_list->next);
}

int	order_tbl(char *s1, char *s2)
{
	if (_strlen_(s1) > _strlen_(s2))
		return (1);
	else if (_strlen_(s1) < _strlen_(s2))
		return (-1);
	return (_strcmp_(s1, s2));
}

void	_memcopy_(char *dest, const char *src, int size)
{
	while (size--)
		*dest++ = *src++;
	dest[size] = '\0';
}
