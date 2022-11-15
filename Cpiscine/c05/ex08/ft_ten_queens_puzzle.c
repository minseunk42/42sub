/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:36:13 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/04 09:24:16 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	abs(int val)
{
	if (val < 0)
		val = -val;
	return (val);
}

int	check_pos(int dep, char *arr, int pos)
{
	int	i;

	i = 0;
	while (i < dep)
	{
		if (arr[i] - '0' == pos)
			return (0);
		if (abs(arr[i] - '0' - pos) == abs((i - dep)))
			return (0);
		i++;
	}
	return (1);
}

void	tq(int dep, char *arr, int *cnt)
{
	int	pos;

	if (dep == 10)
	{
		*cnt += 1;
		write(1, arr, 10);
		write(1, "\n", 1);
		return ;
	}
	pos = 0;
	while (pos <= 9)
	{
		if (check_pos(dep, arr, pos))
		{
			arr[dep] = '0' + pos;
			tq(dep + 1, arr, cnt);
		}
		pos++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	arr[11];
	int		cnt;
	int		i;

	i = -1;
	while (++i < 10)
		arr[i] = 0;
	cnt = 0;
	tq(0, arr, &cnt);
	return (cnt);
}
