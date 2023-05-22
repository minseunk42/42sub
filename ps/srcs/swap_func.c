/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:27:11 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/22 12:03:15 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	sa(t_stack st_arr[])
{
	int temp;

	if (!st_arr[SA].head || !st_arr[SA].head->next)
		return (-1);
	temp = st_arr[SA].head->value;
	st_arr[SA].head->value = st_arr[SA].head->next->value;
	st_arr[SA].head->next->value = temp;
	return (0);
}

int	sb(t_stack st_arr[])
{
	int temp;

	if (!st_arr[SB].head || !st_arr[SB].head->next)
		return (-1);
	temp = st_arr[SB].head->value;
	st_arr[SB].head->value = st_arr[SB].head->next->value;
	st_arr[SB].head->next->value = temp;
	return (0);
}

int	ss(t_stack st_arr[])
{
	if (sa(st_arr))
		return (-1);
	if (sb(st_arr))
		return (-1);
	return (0);
}
