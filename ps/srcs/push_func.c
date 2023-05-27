/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:18:21 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/27 20:56:11 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	pa(t_stack st_arr[])
{
	if (!(st_arr[STB].head))
		return (-1);
	push_head(&st_arr[STA], pop_head(&st_arr[STB]));
	return (0);
}

int	pb(t_stack st_arr[])
{
	if (!(st_arr[STA].head))
		return (-1);
	push_head(&st_arr[STB], pop_head(&st_arr[STA]));
	return (0);
}
