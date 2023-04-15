/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:08:39 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/15 23:42:17 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_chr(t_format form, va_list *ap, int *cnt)
{
	char	temp;

	temp = va_arg(*ap, int);
	if (form.widt > 1)
		(*cnt) += form.widt;
	else
		(*cnt) += 1;
	if (form.flag & MNS)
	{
		if (putchar_proc_error(temp) == -1)
			return (-1);
	}
	if (print_space(form, (form.widt - 1)) == -1)
		return (-1);
	if (!(form.flag & MNS))
	{
		if (putchar_proc_error(temp) == -1)
			return (-1);
	}
	return (0);
}
