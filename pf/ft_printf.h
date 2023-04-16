/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:46:30 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/16 20:35:26 by minseunk         ###   ########.fr       */
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
# define PCT 6
# define HEX0 7
# define HEX1 8
# define MNS 0b00001
# define PLS 0b00010
# define SHP 0b00100
# define SPC 0b01000
# define ZRO 0b10000

int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		putchar_proc_error(char c, int *cnt);
int		print_space(t_format form, int widt, int *cnt);
void	set_format(char **str, t_format *form);
int		print_chr(t_format form, va_list *ap, int *cnt);
int		print_hex(t_format form, va_list *ap, int *cnt);
int		print_int(t_format form, va_list *ap, int *cnt);
int		print_pct(t_format form, va_list *ap, int *cnt);
int		print_ptr(t_format form, va_list *ap, int *cnt);
int		print_str(t_format form, va_list *ap, int *cnt);
int		print_usi(t_format form, va_list *ap, int *cnt);
int		ft_printf(const char *str, ...);

#endif
