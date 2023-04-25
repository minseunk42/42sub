/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:39:10 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/25 21:18:59 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}



t_list	*ft_lstnew(void *content);
int	ft_printf(const char *str, ...);


int	main(int ac, char **av)
{
	t_list *lst;

	(void)av;
	(void)ac;
	int *tmp = (int *)malloc(sizeof(int));
	 
	*tmp = 3;
	lst = ft_lstnew(tmp);
	ft_printf("%d", *(int *)lst->content);
}
