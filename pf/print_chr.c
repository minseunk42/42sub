/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:08:39 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/06 18:22:07 by ubuntu           ###   ########.fr       */
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
	if (print_widt(form, 0) == -1)
		return (-1);
	if (!(form.flag & MNS))
	{
		if (putchar_proc_error(va_arg(*ap, int)) == -1)
			return (-1);
	}
	return (0);
}
