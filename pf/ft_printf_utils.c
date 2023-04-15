/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:20:08 by ubuntu            #+#    #+#             */
/*   Updated: 2023/04/15 23:43:26 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstr_proc_error(char *str, t_format form)
{
	int	flag;
	int	outlen;

	if (form.prec < 0)
		outlen = ft_strlen((const char *)str);
	else
		outlen = form.prec;
	flag = write(1, str, outlen);
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

int	print_space(t_format form, int widt)
{
	int	i;
	int	flag;

	i = 0;
	while (++i <= widt)
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
