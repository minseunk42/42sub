/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:08:39 by minseunk          #+#    #+#             */
/*   Updated: 2023/03/27 15:38:23 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_chr(t_format form, va_list *ap, int *cnt)
{
	if (form.widt > 1)
		*cnt += form.widt;
	else
		(*cnt)++;
	if (form.flag & MNS)
	{
		if (putchar_proc_error(va_arg(*ap, int)) == -1)
			return (-1);
	}
	if (print_widt(form) == -1)
		return (-1);
	if (!(form.flag & MNS))
	{
		if (putchar_proc_error(va_arg(*ap, int)) == -1)
			return (-1);
	}
	return (0);
}
