/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:18:11 by minseunk          #+#    #+#             */
/*   Updated: 2023/03/26 21:57:12 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstr_proc_error(char *str)
{
	int	flag;

	flag = write(1, str, ft_strlen((const char *)str));
	if (flag == -1)
		return (-1);
	return (0);
}

int	print_widt(t_format form, int widt)
{
	int	i;

	i = 0;
	while (++i < widt)
	{
		if (((form.flag & ZRO) == form.flag) && (putstr_proc_error('0') == -1))
			return (-1);
		else if ((putstr_proc_error(' ') == -1))
			return (-1);
	}
}

int	set_cnt(t_format form, va_list *ap, int *cnt)
{
	va_list	cp;
	char	*str;

	va_copy(cp, *ap);
	str = va_args(cp);
	if (ft_strlen(str) >= form.widt)
		*cnt = ft_strlen(str);
	else
		*cnt += form.widt;
	return (form.widt - ft_strlen(str));
}

int	print_str(t_format form, va_list *ap, int *cnt)
{
	int		width;

	width = set_cnt(form, ap, cnt);
	if (form.flag & MNS)
	{
		if (putstr_proc_error(va_args(*ap, int)) == -1)
			return (-1);
	}
	if (print_widt(form, width) == -1)
		return (-1);
	if (form.flag & MNS)
	{
		if (putstr_proc_error(va_args(*ap, int)) == -1)
			return (-1);
	}
	return (0);
}
