/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:18:11 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/04 13:48:35 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int		width;

	width = set_cnt(form, ap, cnt);
	if (form.flag & MNS)
	{
		if (putstr_proc_error(va_arg(*ap, char *)) == -1)
			return (-1);
	}
	if (print_widt(form, width) == -1)
		return (-1);
	if (!(form.flag & MNS))
	{
		if (putstr_proc_error(va_arg(*ap, char *)) == -1)
			return (-1);
	}
	return (0);
}
