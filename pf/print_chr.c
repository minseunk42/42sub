/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:08:39 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/21 20:43:50 by ubuntu           ###   ########.fr       */
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
