/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_func.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:53:13 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/19 19:00:58 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int ra(t_stack st_arr[])
{
    if (!st_arr[SA].head || !st_arr[SA].head->next)
        return (-1);
    push_tail(&(st_arr[SA]), pop_head(&(st_arr[SA])));
    return (0);
}

int rb(t_stack st_arr[])
{
    if (!st_arr[SB].head || !st_arr[SB].head->next)
        return (-1);
    push_tail(&(st_arr[SB]), pop_head(&(st_arr[SB])));
    return (0);
}

int rr(t_stack st_arr[])
{
    if (ra(st_arr))
        return (-1);
    if (rb(st_arr))
        return (-1);
    return (0);
}