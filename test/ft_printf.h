/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:46:30 by minseunk          #+#    #+#             */
/*   Updated: 2023/03/04 21:25:52 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_format
{
	int	flag;
	int	widt;
	int	prec;
	int	type;
}	t_format;

# define CHR 1
# define STR 2
# define PTR 3
# define INT 4
# define USI 5
# define HEX 6
# define PCT 7

# define MNS 0b10000
# define PLS 0b01000
# define SHP 0b00100
# define SPC 0b00010
# define ZRO 0b00001

void	set_format(char **str, t_format *form);
int		print_chr(t_format form, va_list ap, int *cnt);
int		print_hex(t_format form, va_list ap, int *cnt);
int		print_int(t_format form, va_list ap, int *cnt);
int		print_pct(t_format form, va_list ap, int *cnt);
int		print_ptr(t_format form, va_list ap, int *cnt);
int		print_str(t_format form, va_list ap, int *cnt);
int		print_usi(t_format form, va_list ap, int *cnt);

#endif
