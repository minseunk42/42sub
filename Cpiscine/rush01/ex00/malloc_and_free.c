/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:48:28 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/09 22:02:18 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_n(int cnt, int *n)
{
	*n = 0;
	while (++(*n) < 10)
	{
		if (cnt % ((*n) * 4) == 0 && cnt / (*n) == 4)
			return (1);
	}
	return (0);
}

int	proc_argv(char *argv)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 1;
	while (*argv)
	{
		if (flag)
		{
			if (!('0' <= *argv && *argv <= '9'))
				return (0);
			cnt++;
			flag--;
		}
		else
		{
			if (*argv != ' ')
				return (0);
			flag++;
		}
		argv++;
	}
	if (*(--argv) == ' ')
		return (0);
	return (cnt);
}

int	*put_argument(int n, char *argv)
{
	int	*arr;
	int	arr_idx;
	int	i;

	arr = (int *)malloc(sizeof(int) * (4 * n) + 4);
	arr_idx = 1;
	arr[0] = n;
	while (*argv && arr_idx <= (4 * n))
	{
		if (*argv != ' ')
			arr[arr_idx++] = *argv - '0';
		argv++;
	}
	i = -1;
	return (arr);
}

int	**mk_n_table(int n)
{
	int	**table;
	int	i;

	table = (int **)malloc(sizeof(int *) * n);
	if (!table)
		return (0);
	table[0] = (int *)malloc(sizeof(int) * (n * n));
	if (!table[0])
		return (0);
	i = 0;
	while (++i < n)
		table[i] = table[i - 1] + n;
	return (table);
}

void	free_all(int **table, int *view)
{
	free(table[0]);
	free(table);
	free(view);
}
