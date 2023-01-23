/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pirntf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:41:52 by minseunk          #+#    #+#             */
/*   Updated: 2023/01/23 19:25:06 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_type(char c)
{
	char	*str;
	int		i;

	str = "cspdiuxX%";
	while (str[i])
	{
		if (c == str[i++])
			return (i);
	}
	return (0);
}

void	set_format(char **str, t_format *form)
{
	form->type = 0;
	while (!(form->type))
	{
		
	}
	form->type = is_type(**str);
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
	set_format(++str, &form);
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
