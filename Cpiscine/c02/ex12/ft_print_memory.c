/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:52:39 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/17 10:20:37 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_addr(unsigned long long addr)
{
	int		arr[16];
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		arr[i--] = addr % 16;
		addr /= 16;
	}
	while (++i < 16)
		write(1, &hex[(arr[i])], 1);
	write(1, ": ", 2);
}

void	print_hex(unsigned char *addr, int size)
{
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = -1;
	while (i++ < size - 1)
	{
		write(1, &(hex[*addr / 16]), 1);
		write(1, &(hex[*addr % 16]), 1);
		addr++;
		if (i % 2 == 1)
			write(1, " ", 1);
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	print_val(unsigned char *addr, int size)
{
	int	i;

	i = -1;
	while (i++ < size - 1)
	{	
		if (' ' > *addr || '~' < *addr)
			write(1, ".", 1);
		else
			write(1, addr, 1);
		addr++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	if (size == 0)
		return (addr);
	while (size > 16)
	{
		print_addr((unsigned long long)addr);
		print_hex((unsigned char *)addr, 16);
		print_val((unsigned char *)addr, 16);
		addr += 16;
		size -= 16;
	}
	print_addr((unsigned long long)addr);
	print_hex((unsigned char *)addr, size);
	print_val((unsigned char *)addr, size);
	return (addr);
}
