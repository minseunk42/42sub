/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:19:40 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/23 01:40:54 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putzero_hex(unsigned int nb, t_format form, int *cnt)
{
	char	*str;
	int		i;
	int		nlen;
	int		zlen;

	str = utoh(nb);
	nlen = ft_strlen(str);
	zlen = 0;
	if (form.prec >= 0)
		zlen = form.prec - nlen;
	else if ((form.flag & ZRO) && (form.widt > nlen))
		zlen = form.widt - nlen;
	if (form.prec < 0 && (form.flag & SHP) && (form.flag & ZRO) && nb)
		zlen -= 2;
	i = -1;
	while (++i < zlen)
	{
		if (putchar_proc_error('0', cnt) == -1 && free_str(str))
			return (-1);
	}
	free(str);
	return (0);
}

int	putox(unsigned int nb, t_format form, int *cnt)
{
	if (!nb)
		return (0);
	if (form.flag & SHP)
	{
		if (putchar_proc_error('0', cnt) == -1)
			return (-1);
		if (form.type == HXS && putchar_proc_error('x', cnt) == -1)
			return (-1);
		else if (form.type == HXR && putchar_proc_error('X', cnt) == -1)
			return (-1);
	}
	return (0);
}

int	puthex(unsigned int nb, t_format form, int *cnt)
{
	char	*str;
	int		i;

	str = utoh(nb);
	if (form.type == HXR)
	{
		i = -1;
		while (str[++i])
			str[i] = ft_toupper(str[i]);
	}
	if (putox(nb, form, cnt) == -1 && free_str(str))
		return (-1);
	if ((!(form.flag & MNS) || form.prec > 0)
		&& putzero_hex(nb, form, cnt) == -1 && free_str(str))
		return (-1);
	i = (!nb && !form.prec);
	while (str[i])
	{
		if (putchar_proc_error(str[i++], cnt) == -1 && free_str(str))
			return (-1);
	}
	free(str);
	return (0);
}

int	get_spwi_hex(t_format form, va_list *ap)
{
	va_list			cp;
	char			*str;
	int				strlen;
	unsigned int	nb;

	if (!(form.flag & MNS) && form.flag & ZRO && form.prec < 0)
		return (0);
	va_copy(cp, *ap);
	nb = va_arg(cp, unsigned int);
	str = utoh(nb);
	if (form.prec > ft_strlen(str))
		strlen = form.prec;
	else if (!form.prec && !nb)
		strlen = 0;
	else
		strlen = ft_strlen(str);
	if (form.flag & SHP && nb)
		strlen += 2;
	va_end(cp);
	free(str);
	return (form.widt - strlen);
}

int	print_hex(t_format form, va_list *ap, int *cnt)
{
	int	sp_width;

	sp_width = get_spwi_hex(form, ap);
	if (form.flag & MNS)
	{
		if (puthex(va_arg(*ap, unsigned int), form, cnt) == -1)
			return (-1);
	}
	if (print_space(sp_width, cnt) == -1)
		return (-1);
	if (!(form.flag & MNS))
	{
		if (puthex(va_arg(*ap, unsigned int), form, cnt) == -1)
			return (-1);
	}
	return (0);
}
