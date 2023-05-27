/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:53:13 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/27 20:55:32 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	rra(t_stack st_arr[])
{
	if (!st_arr[STA].head || !st_arr[STA].head->next)
		return (-1);
	push_head(&(st_arr[STA]), pop_tail(&(st_arr[STA])));
	return (0);
}

int	rrb(t_stack st_arr[])
{
	if (!st_arr[STB].head || !st_arr[STB].head->next)
		return (-1);
	push_head(&(st_arr[STB]), pop_tail(&(st_arr[STB])));
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
