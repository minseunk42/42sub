/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_and_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyep <sanghyep@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:32:42 by sanghyep          #+#    #+#             */
/*   Updated: 2022/10/09 22:03:46 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	no_dup(int **table, int row, int col, int n)
{
	int	value;
	int	idx;

	idx = 0;
	value = table[row][col];
	while (idx < n)
	{
		if (idx != col && table[row][idx] == value)
			return (0);
		if (idx != row && table[idx][col] == value)
			return (0);
		idx++;
	}
	return (1);
}

void	print_answer(int **table, int n)
{
	int		row;
	int		col;
	char	now;

	row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{	
			now = table[row][col] + '0';
			write(1, &now, 1);
			if (col == n - 1)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
			col++;
		}
		row++;
	}
}
