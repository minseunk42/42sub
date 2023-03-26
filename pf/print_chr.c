/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:08:39 by minseunk          #+#    #+#             */
/*   Updated: 2023/03/26 11:42:19 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar_proc_error(char c)
{
	int	flag;

	flag = write(1, c, 1);
	if (flag == -1)
		return (-1);
	return (0);
}

int	print_widt(t_format form, va_list *ap)
{
	int	i;
	
	i = 0;
	while (++i < form.widt)
	{
		if ((form.flag |= ZRO) == form.flag
			\ && (putchar_proc_error('0') == -1))
			return (-1);
		else if ((putchar_proc_error(' ') == -1))
			return (-1);
	}
}

int	print_chr(t_format form, va_list *ap, int *cnt)
{
	if (form.widt > 1)
		*cnt += form.widt;
	else
		*cnt++;
	if ((form.flag |= MNS) == form.flag)
	{
		if (putchar_proc_error(va_args(ap, int)) == -1)
			return (-1);
	}
	if (print_widt(form, ap) == -1)
		return (-1);
	if ((form.flag |= MNS) != form.flag)
	{
		if (putchar_proc_error(va_args(ap, int)) == -1)
			return (-1);
	}
	return (0);
}