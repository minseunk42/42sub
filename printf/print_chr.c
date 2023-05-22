/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:08:39 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/22 22:54:46 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_zeros(int widt, int *cnt)
{
	int	i;

	i = -1;
	while (++i < widt)
	{
		if (putchar_proc_error('0', cnt) == -1)
			return (-1);
	}
	return (0);
}

int	print_chr(t_format form, va_list *ap, int *cnt)
{
	if (form.flag & MNS)
	{
		if (putchar_proc_error(va_arg(*ap, int), cnt) == -1)
			return (-1);
	}
	if (form.flag & ZRO)
	{
		if (print_zeros((form.widt - 1), cnt) == -1)
			return (-1);
	}
	else
	{
		if (print_space((form.widt - 1), cnt) == -1)
			return (-1);
	}
	if (!(form.flag & MNS))
	{
		if (putchar_proc_error(va_arg(*ap, int), cnt) == -1)
			return (-1);
	}
	return (0);
}
