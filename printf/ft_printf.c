/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:41:52 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/28 05:07:45 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char **str, va_list *ap, int *cnt)
{
	int			(*fp[9])(t_format, va_list *, int *);
	t_format	form;

	fp[PCT] = print_pct;
	fp[CHR] = print_chr;
	fp[STR] = print_str;
	fp[INT] = print_int;
	fp[USI] = print_usi;
	fp[PTR] = print_ptr;
	fp[HXS] = print_hex;
	fp[HXR] = print_hex;
	set_format(str, &form);
	if (!form.type)
		return (-1);
	return (fp[form.type](form, ap, cnt));
}

int	proc_str(char *str, va_list *ap)
{
	int	cnt;
	int	flag;

	cnt = 0;
	while (*str)
	{
		if (*str != '%' && ++cnt)
			flag = write(1, str++, 1);
		else if (str++)
			flag = print_format(&str, ap, &cnt);
		if (flag == -1)
			return (-1);
	}
	return (cnt);
}

int	ft_printf(const char *str, ...)
{
	int		out;
	va_list	ap;

	va_start(ap, str);
	out = proc_str((char *)str, &ap);
	va_end(ap);
	return (out);
}
