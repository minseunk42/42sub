/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:27:11 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/27 20:55:48 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	sa(t_stack st_arr[])
{
	int	temp[2];

	if (!st_arr[STA].head || !st_arr[STA].head->next)
		return (-1);
	temp[NUM] = st_arr[STA].head->val[NUM];
	temp[ORDER] = st_arr[STA].head->val[ORDER];
	st_arr[STA].head->val[NUM] = st_arr[STA].head->next->val[NUM];
	st_arr[STA].head->val[ORDER] = st_arr[STA].head->next->val[ORDER];
	st_arr[STA].head->next->val[NUM] = temp[NUM];
	st_arr[STA].head->next->val[ORDER] = temp[ORDER];
	return (0);
}

int	sb(t_stack st_arr[])
{
	int	temp[2];

	if (!st_arr[STB].head || !st_arr[STB].head->next)
		return (-1);
	temp[NUM] = st_arr[STB].head->val[NUM];
	temp[ORDER] = st_arr[STB].head->val[ORDER];
	st_arr[STB].head->val[NUM] = st_arr[STB].head->next->val[NUM];
	st_arr[STB].head->val[ORDER] = st_arr[STB].head->next->val[ORDER];
	st_arr[STB].head->next->val[NUM] = temp[NUM];
	st_arr[STB].head->next->val[ORDER] = temp[ORDER];
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
