/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:43:44 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/18 20:34:18 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	void	*cont;
	void	*new;

	if (!lst || !f || !del)
		return (0);
	out = 0;
	while (lst)
	{
		cont = f(lst->content);
		new = ft_lstnew(cont);
		if (!new)
		{
			ft_lstclear(&out, del);
			del(cont);
			return (0);
		}
		ft_lstadd_back(&out, new);
		lst = lst->next;
	}
	return (out);
}
