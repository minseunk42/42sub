/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:18:21 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/19 14:25:55 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int pa(t_stack st_arr[])
{
    if (!(st_arr[SB].head))
        return (-1);
    push_head(&st_arr[SA], pop_head(&st_arr[SB]));
    return (0);
}

int pb(t_stack st_arr[])
{
    if (!(st_arr[SA].head))
        return (-1);
    push_head(&st_arr[SB], pop_head(&st_arr[SA]));
    return (0);
}