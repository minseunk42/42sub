/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:20:08 by ubuntu            #+#    #+#             */
/*   Updated: 2023/04/04 13:48:42 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstr_proc_error(char *str)
{
	int	flag;

	flag = write(1, str, ft_strlen((const char *)str));
	if (flag == -1)
		return (-1);
	return (0);
}

int	putchar_proc_error(char c)
{
	int	flag;

	flag = write(1, &c, 1);
	if (flag == -1)
		return (-1);
	return (0);
}

int	print_widt(t_format form, int widt)
{
	int	i;
	int flag;
	
	i = 0;
	if (widt != 0)
		form.widt = widt;
	while (++i <= form.widt)
	{
		if (form.flag & ZRO)
			flag = putchar_proc_error('0');
		else
			flag = putchar_proc_error(' ');
		if (flag == -1)
			return (-1);
	}
	return (0);
}