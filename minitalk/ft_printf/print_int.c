/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:19:17 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/23 00:14:30 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putsign_int(int nb, t_format form, int *cnt)
{
	int	flag;

	flag = 0;
	if (nb >= 0)
	{
		if (form.flag & PLS)
			flag = putchar_proc_error('+', cnt);
		else if (form.flag & SPC)
			flag = putchar_proc_error(' ', cnt);
	}
	else
		flag = putchar_proc_error('-', cnt);
	if (flag == -1)
		return (-1);
	return (0);
}

int	putzero_int(int nb, t_format form, int *cnt)
{
	char	*str;
	int		i;
	int		nlen;
	int		zlen;

	zlen = 0;
	str = ft_itoa(nb);
	nlen = ft_strlen(str) - (nb < 0);
	if (form.prec >= 0)
		zlen = form.prec - nlen;
	else if ((form.flag & ZRO) && (form.widt > nlen))
	{
		zlen = form.widt - nlen;
		zlen -= ((nb < 0) || (form.flag & PLS) || (form.flag & SPC));
	}
	i = -1;
	while (++i < zlen)
	{
		if (putchar_proc_error('0', cnt) == -1 && free_str(str))
			return (-1);
	}
	free(str);
	return (0);
}

int	putnbr(int nb, t_format form, int *cnt)
{
	char	*str;
	int		i;

	str = ft_itoa(nb);
	if (putsign_int(nb, form, cnt) == -1 && free_str(str))
		return (-1);
	if ((!(form.flag & MNS) || form.prec > 0)
		&& putzero_int(nb, form, cnt) == -1 && free_str(str))
		return (-1);
	i = ((nb < 0) || (!nb && !form.prec));
	while (str[i])
	{
		if (putchar_proc_error(str[i++], cnt) == -1 && free_str(str))
			return (-1);
	}
	free(str);
	return (0);
}

int	get_spwi_int(t_format form, va_list *ap)
{
	va_list	cp;
	char	*str;
	int		strlen;
	int		nb;

	if (!(form.flag & MNS) && form.flag & ZRO && form.prec < 0)
		return (0);
	va_copy(cp, *ap);
	nb = va_arg(cp, int);
	str = ft_itoa(nb);
	if (form.prec > ft_strlen(str))
		strlen = form.prec;
	else if (!form.prec && !nb)
		strlen = 0;
	else
		strlen = ft_strlen(str);
	if (nb >= 0 && ((form.flag & SPC) || (form.flag & PLS)))
		strlen += 1;
	if (nb < 0 && form.prec >= ft_strlen(str) && form.widt > form.prec)
		strlen += 1;
	va_end(cp);
	free(str);
	return (form.widt - strlen);
}

int	print_int(t_format form, va_list *ap, int *cnt)
{
	int	sp_width;

	sp_width = get_spwi_int(form, ap);
	if (form.flag & MNS)
	{
		if (putnbr(va_arg(*ap, int), form, cnt) == -1)
			return (-1);
	}
	if (print_space(sp_width, cnt) == -1)
		return (-1);
	if (!(form.flag & MNS))
	{
		if (putnbr(va_arg(*ap, int), form, cnt) == -1)
			return (-1);
	}
	return (0);
}
