/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_func.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:53:13 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/24 19:35:24 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	ra(t_stack st_arr[])
{
	if (!st_arr[STA].head || !st_arr[STA].head->next)
		return (-1);
	push_tail(&(st_arr[STA]), pop_head(&(st_arr[STA])));
	return (0);
}

int	rb(t_stack st_arr[])
{
	if (!st_arr[STB].head || !st_arr[STB].head->next)
		return (-1);
	push_tail(&(st_arr[STB]), pop_head(&(st_arr[STB])));
	return (0);
}

int	rr(t_stack st_arr[])
{
	if (ra(st_arr))
		return (-1);
	if (rb(st_arr))
		return (-1);
	return (0);
}
