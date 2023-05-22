/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:53:13 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/22 12:02:14 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	rra(t_stack st_arr[])
{
	if (!st_arr[SA].head || !st_arr[SA].head->next)
		return (-1);
	push_head(&(st_arr[SA]), pop_tail(&(st_arr[SA])));
	return (0);
}

int	rrb(t_stack st_arr[])
{
	if (!st_arr[SB].head || !st_arr[SB].head->next)
		return (-1);
	push_head(&(st_arr[SB]), pop_tail(&(st_arr[SB])));
	return (0);
}

int	rrr(t_stack st_arr[])
{
	if (rra(st_arr))
		return (-1);
	if (rrb(st_arr))
		return (-1);
	return (0);
}
