/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:20:11 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/13 19:53:01 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

t_token	*get_last_token(t_token *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_token(t_token **lst, t_token *new)
{
	if (!(*lst))
		*lst = new;
	else
		get_last_token(*lst)->next = new;
}

t_token	*create_token(t_type type, char *data)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (0);
	new->type = type;
	new->data = ft_strdup(data);
	new->next = 0;
	return (new);
}
