/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:17:42 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/24 13:15:35 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putsign_ptr(t_format form, int *cnt)
{
	int	flag;

	if (putchar_proc_error('0', cnt) == -1)
		return (-1);
	if (putchar_proc_error('x', cnt) == -1)
		return (-1);
	return (0);
}

int	putzero_ptr(unsigned long long nb, t_format form, int *cnt)
{
	char	*str;
	int		i;
	int		nlen;
	int		zlen;

	str = ulltoh(nb);
	nlen = ft_strlen(str);
	zlen = 0;
	if (form.prec >= 0)
		zlen = form.prec - nlen;
	else if ((form.flag & ZRO) && (form.widt > nlen))
		zlen = form.widt - nlen;
	i = -1;
	while (++i < zlen)
	{
		if (putchar_proc_error('0', cnt) == -1 && free_str(str))
			return (-1);
	}
	free(str);
	return (0);
}

int	putptr(unsigned long long nb, t_format form, int *cnt)
{
	char	*str;
	int		i;

	str = ulltoh(nb);
	if (putsign_ptr(form, cnt) == -1 && free_str(str))
		return (-1);
	if (putzero_ptr(nb, form, cnt) == -1 && free_str(str))
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

int	get_spwi_ptr(t_format form, va_list *ap)
{
	va_list				cp;
	char				*str;
	int					strlen;
	unsigned long long	nb;

	if (!(form.flag & MNS) && form.flag & ZRO)
		return (0);
	va_copy(cp, *ap);
	nb = va_arg(cp, unsigned long long);
	str = ulltoh(nb);
	if (form.prec > ft_strlen(str))
		strlen = form.prec;
	else if (!form.prec && !nb)
		strlen = 0;
	else
		strlen = ft_strlen(str) + 2;
	if ((form.flag & SPC) || (form.flag & PLS))
		strlen += 1;
	va_end(cp);
	free(str);
	return (form.widt - strlen);
}

int	print_ptr(t_format form, va_list *ap, int *cnt)
{
	int	sp_width;

	sp_width = get_spwi_ptr(form, ap);
	if (form.flag & MNS)
	{
		if (putptr(va_arg(*ap, unsigned long long), form, cnt) == -1)
			return (-1);
	}
	if (print_space(sp_width, cnt) == -1)
		return (-1);
	if (!(form.flag & MNS))
	{
		if (putptr(va_arg(*ap, unsigned long long), form, cnt) == -1)
			return (-1);
	}
	return (0);
}
