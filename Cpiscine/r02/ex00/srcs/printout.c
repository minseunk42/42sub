/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:23:52 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/16 18:31:57 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/num.h"

void	print_unit(int unit, t_list *dict, int flag)
{
	int		i;
	t_list	*temp;

	if (!unit || !flag)
		return ;
	temp = dict;
	while (_strcmp_(temp->key, "1000"))
		temp = temp->next;
	i = 0;
	while (++i < unit)
		temp = temp->next;
	_putstr_(temp->val);
	write(1, " ", 1);
}

void	print_val(char *ref, t_list *dict)
{
	t_list	*temp;

	temp = dict;
	while (temp->next && _strcmp_(temp->key, ref))
		temp = temp->next;
	_putstr_(temp->val);
	write(1, " ", 1);
}

void	print_h(char *num, t_list *dict, int *flag)
{
	char	ref[2];

	*flag = 1;
	ref[0] = num[0];
	ref[1] = 0;
	print_val(ref, dict);
	print_val("100", dict);
}

void	print_t(char *num, t_list *dict, int *flag)
{
	char	ref[3];

	*flag = 1;
	if (num[0] == '1')
	{
		ref[0] = num[0];
		ref[1] = num[1];
		ref[2] = 0;
		print_val(ref, dict);
		return ;
	}
	ref[0] = num[0];
	ref[1] = '0';
	ref[2] = 0;
	print_val(ref, dict);
}

void	print_o(char *num, t_list *dict, int *flag)
{
	char	ref[2];

	*flag = 1;
	ref[0] = num[0];
	ref[1] = 0;
	print_val(ref, dict);
}
