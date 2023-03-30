/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:41:52 by minseunk          #+#    #+#             */
/*   Updated: 2023/03/27 15:36:18 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_format(char **str, va_list *ap, int *cnt)
{
	int			(*fp[7])(t_format , va_list *, int *);
	t_format	form;

	fp[CHR] = print_chr;
	/*sfp[STR] = print_str;
	fp[PTR] = print_ptr;
	fp[INT] = print_int;
	fp[USI] = print_usi;
	fp[HEX] = print_hex; */
	fp[PCT] = print_pct;
	set_format(str, &form);
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
		else if (str++)
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

int main()
{
	printf("%d",ft_printf("22%%%03c%3%%- 3c%c",'a','b'));
}