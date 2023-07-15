/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:20:11 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/14 18:44:49 by minseunk         ###   ########.fr       */
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

t_token	*create_token(t_ttype ttype, t_qtype qtype, char *data)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (0);
	new->ttype = ttype;
	new->qtype = qtype;
	if (data[0])
		new->data = ft_strdup(data);
	else
		new->data = ft_strdup("(null)");
	new->next = 0;
	return (new);
}
