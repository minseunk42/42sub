/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:18:11 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/16 21:27:09 by minseunk         ###   ########.fr       */
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
	i = -1;
	if (form.prec < 0 || form.prec > 6)
		form.prec = 6;
	while (++i < form.prec)
	{
		flag = putchar_proc_error(null[i], cnt);
		if (flag == -1)
			return (-1);
	}
	return (0);
}

int	putstr_proc_error(char *str, t_format form, int *cnt)
{
	int	flag;
	int	i;
	int	len;

	i = 0;
	if (form.prec >= 0)
		len = form.prec;
	else
		len = ft_strlen(str);
	if (str == NULL)
	{
		if (putnull(form, cnt))
			return (-1);
	}
	while (i < len && str[i])
	{	
		flag = putchar_proc_error(str[i++], cnt);
		if (flag == -1)
			return (-1);
	}
	return (0);
}

int	get_spwi(t_format form, va_list *ap)
{
	va_list	cp;
	char	*str;
	int		strlen;

	va_copy(cp, *ap);
	str = va_arg(cp, char *);
	strlen = 0;
	if (form.prec >= 0 && form.prec < ft_strlen(str))
		strlen = form.prec;
	else
		strlen = ft_strlen(str);
	if (str == NULL)
		strlen = 6 - (form.prec * (form.prec >= 0 && form.prec < 6));
	return (form.widt - strlen);
}

int	print_str(t_format form, va_list *ap, int *cnt)
{
	int		sp_width;

	sp_width = get_spwi(form, ap);
	if (form.flag & MNS)
	{
		if (putstr_proc_error(va_arg(*ap, char *), form, cnt) == -1)
			return (-1);
	}
	if (print_space(form, sp_width, cnt) == -1)
		return (-1);
	if (!(form.flag & MNS))
	{
		if (putstr_proc_error(va_arg(*ap, char *), form, cnt) == -1)
			return (-1);
	}
	return (0);
}
