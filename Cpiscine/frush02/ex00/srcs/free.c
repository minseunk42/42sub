/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:57:33 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/16 19:29:39 by kelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rm_all_list(t_list *head)
{
	t_list	*rm_list;

	while (head->next)
	{
		rm_list = head->next;
		head->next = rm_list->next->next;
		free(rm_list->key);
		free(rm_list->value);
		free(rm_list);
	}
}
