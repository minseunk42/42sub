/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:43:44 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/16 20:22:09 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*temp;

	if (!lst || !f || !del)
		return (0);
	out = ft_lstnew(f(lst->content));
	temp = out;
	lst = lst->next;
	while (lst)
	{
		temp->next = ft_lstnew(f(lst->content));
		if (!(ft_lstlast(out)))
		{
			ft_lstclear(&out, del);
			return (0);
		}
		lst = lst->next;
		temp = temp->next;
	}
	return (out);
}
