/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:46:30 by minseunk          #+#    #+#             */
/*   Updated: 2023/02/18 19:24:27 by minseunk         ###   ########.fr       */
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

int	print_chr(t_format form, va_list ap, int *cnt);

# define CHR 0
# define STR 1
# define PTR 2
# define INT 3
# define USI 4
# define HEX 5
# define PCT 6

#endif
