/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pirntf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:41:52 by minseunk          #+#    #+#             */
/*   Updated: 2023/02/26 05:31:01 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_type(char **str)
{
	while ((*str)++)
	{
		if (**str == 'c' && (*str)++)
			return (CHR);
		if (**str == 's' && (*str)++)
			return (STR);
		if (**str == 'p' && (*str)++)
			return (PTR);
		if (**str == 'd' && (*str)++)
			return (INT);
		if (**str == 'i' && (*str)++)
			return (INT);
		if (**str == 'u' && (*str)++)
			return (USI);
		if (**str == 'x' && (*str)++)
			return (HEX);
		if (**str == 'X' && (*str)++)
			return (HEX);
		if (**str == '%' && (*str)++)
			return (PCT);
	}
	return (-1);
}

int	set_flag(char *str)
{
	
}

void	set_format(char **str, t_format *form)
{
	form->flag = set_flag(*str);
	form->widt = set_widt(*str);
	form->prec = set_prec(*str);
	form->type = set_type(str);
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
