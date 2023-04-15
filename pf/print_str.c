/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:18:11 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/15 23:37:18 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnull(t_format form, int *cnt)
{
	int		flag;
	int		i;
	char	*null;

	flag = 0;
	null = "(null)";
	i = 0;
	if (form.prec < 0)
		form.prec = 6;
	while (i < form.prec)
	{
		flag = write(1, &(null[i++]), 1);
		if (flag == -1)
			return (-1);
		*cnt += 1;
	}
	return (0);
}

int	set_cnt(t_format form, va_list *ap, int *cnt)
{
	va_list	cp;
	char	*str;

	va_copy(cp, *ap);
	str = va_arg(cp, char *);
	if (ft_strlen(str) >= form.widt)
		*cnt += ft_strlen(str);
	else
		*cnt += form.widt;
	return (form.widt - ft_strlen(str));
}

int	print_str(t_format form, va_list *ap, int *cnt)
{
	va_list	cp;
	int		width;

	width = set_cnt(form, ap, cnt);
	va_copy(cp, *ap);
	if (va_arg(cp, char *) == NULL)
		return (putnull(form, cnt));
	if (form.flag & MNS)
	{
		if (putstr_proc_error(va_arg(*ap, char *), form) == -1)
			return (-1);
	}
	if (print_space(form, width) == -1)
		return (-1);
	if (!(form.flag & MNS))
	{
		if (putstr_proc_error(va_arg(*ap, char *), form) == -1)
			return (-1);
	}
	return (0);
}
