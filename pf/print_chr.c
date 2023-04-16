/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:08:39 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/16 20:39:31 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_chr(t_format form, va_list *ap, int *cnt)
{
	if (form.flag & MNS)
	{
		if (putchar_proc_error(va_arg(*ap, int), cnt) == -1)
			return (-1);
	}
	if (print_space(form, (form.widt - 1), cnt) == -1)
		return (-1);
	if (!(form.flag & MNS))
	{
		if (putchar_proc_error(va_arg(*ap, int), cnt) == -1)
			return (-1);
	}
	return (0);
}
