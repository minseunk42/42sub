/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pirntf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:41:52 by minseunk          #+#    #+#             */
/*   Updated: 2023/02/18 19:50:01 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_type(char *c)
{
	while (++c)
	{
		if (*c == 'c')
			return (CHR);
		if (*c == 's')
			return (STR);
		if (*c == 'p')
			return (PTR);
		if (*c == 'd')
			return (INT);
		if (*c == 'i')
			return (INT);
		if (*c == 'u')
			return (USI);
		if (*c == 'x')
			return (HEX);
		if (*c == 'X')
			return (HEX);
		if (*c == '%')
			return (PCT);
	}
	return (-1);
}

void	set_format(char **str, t_format *form)
{
	form->type = set_type(*str);
	form->flag = set_flag(*str);
	form->widt = set_with(*str);
	form->prec = set_prec(*str);
}

int	print_format(char **str, va_list *ap, int *cnt)
{
	int			(*fp[7])(t_format, va_list *, int *);
	t_format	form;

	fp[CHR] = print_chr;
	fp[STR] = print_str;
	fp[PTR] = print_ptr;
	fp[INT] = print_int;
	fp[USI] = print_usi;
	fp[HEX] = print_hex;
	fp[PCT] = print_pct;
	set_format(str, &form);
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
		else
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
