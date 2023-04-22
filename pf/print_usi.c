/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:28:43 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/21 20:49:53 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int putzero_usi(unsigned int nb, t_format form, int *cnt)
{
	char	*str;
	int 	i;
	int		nlen;
	int		zlen;

	str = utoa(nb);
	nlen = ft_strlen(str);
	if (form.prec >= 0)
		zlen = form.prec - nlen;
	else if((form.flag & ZRO) && (form.widt > nlen))
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

int putusi(unsigned int nb, t_format form, int *cnt)
{
	char	*str;
	int		i;

	str = utoa(nb);
	i = !nb && !form.prec;
	if (!(form.flag & MNS)
		&& putzero_usi(nb, form, cnt) == -1)
		return (-1);
	while (str[i])
	{
		if (putchar_proc_error(str[i++], cnt) == -1 && free_str(str))
			return (-1);
	}
	free(str);
	return (0);
}

int get_spwi_usi(t_format form, va_list *ap)
{
	va_list			cp;
	char			*str;
	int				strlen;
	unsigned int	nb;

	if (!(form.flag & MNS) && form.flag & ZRO)
		return (0);
	va_copy(cp, *ap);
	nb = va_arg(cp, unsigned int);
	str = utoa(nb);
	if (form.prec > ft_strlen(str))
		strlen = form.prec;
	else if (!form.prec && !nb)
		strlen = 0;
	else
		strlen = ft_strlen(str);
	va_end(cp);
	free(str);
	return (form.widt - strlen);
}

int	print_usi(t_format form, va_list *ap, int *cnt)
{
	int	sp_width;

	sp_width = get_spwi_usi(form, ap);
	if (form.flag & MNS)
	{
		if (putusi(va_arg(*ap, unsigned int), form, cnt) == -1)
			return (-1);
	}
	if (print_space(sp_width, cnt) == -1)
		return (-1);
	if (!(form.flag & MNS))
	{
		if (putusi(va_arg(*ap, unsigned int), form, cnt) == -1)
			return (-1);
	}
	return (0);
}
