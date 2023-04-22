/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:18:11 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/21 20:50:03 by ubuntu           ###   ########.fr       */
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

int	putstr(char *str, t_format form, int *cnt)
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
	while (i < len && str != NULL && str[i])
	{	
		flag = putchar_proc_error(str[i++], cnt);
		if (flag == -1)
			return (-1);
	}
	return (0);
}

int	get_spwi_str(t_format form, va_list *ap)
{
	va_list	cp;
	char	*str;
	int		strlen;

	if (!(form.flag & MNS) && form.flag & ZRO)
		return (0);
	va_copy(cp, *ap);
	str = va_arg(cp, char *);
	strlen = 0;
	if (form.prec >= 0 && form.prec < ft_strlen(str))
		strlen = form.prec;
	else
		strlen = ft_strlen(str);
	if (str == NULL)
	{
		if (form.prec >= 6 || form.prec < 0)
			strlen = 6;
		else if (form.prec == 0)
			strlen = 0;
		else
			strlen = form.prec;
	}
	va_end(cp);
	return (form.widt - strlen);
}

int	print_str(t_format form, va_list *ap, int *cnt)
{
	int	sp_width;

	sp_width = get_spwi_str(form, ap);
	if (form.flag & MNS)
	{
		if (putstr(va_arg(*ap, char *), form, cnt) == -1)
			return (-1);
	}
	if (print_space(sp_width, cnt) == -1)
		return (-1);
	if (!(form.flag & MNS))
	{
		if (putstr(va_arg(*ap, char *), form, cnt) == -1)
			return (-1);
	}
	return (0);
}
