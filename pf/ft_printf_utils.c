/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:20:08 by ubuntu            #+#    #+#             */
/*   Updated: 2023/04/16 20:35:29 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar_proc_error(char c, int *cnt)
{
	int	flag;

	flag = write(1, &c, 1);
	if (flag == -1)
		return (-1);
	*cnt += 1;
	return (0);
}

int	print_space(t_format form, int widt, int *cnt)
{
	int	i;
	int	flag;

	i = 0;
	while (++i <= widt)
	{
		if (form.flag & ZRO)
			flag = putchar_proc_error('0', cnt);
		else
			flag = putchar_proc_error(' ', cnt);
		if (flag == -1)
			return (-1);
	}
	return (0);
}
