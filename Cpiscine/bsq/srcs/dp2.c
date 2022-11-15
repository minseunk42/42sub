/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:18:47 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/20 11:58:26 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_answer(char **table, int row, int col)
{
	int		i;
	int		j;
	char	*onerow;

	onerow = (char *)malloc(sizeof(char) * col);
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			onerow[j] = table[i][j];
			j++;
		}
		onerow[j++] = '\n';
		write(1, onerow, col + 1);
		i++;
	}
	free(onerow);
}

char	**mk_answer(int **map, int *pos, int *mi, char *mark)
{
	int		i;
	int		j;
	char	**out;

	out = (char **)malloc(sizeof(char *) * pos[Y]);
	i = -1;
	while (++i < pos[Y])
		out[i] = (char *)malloc(sizeof(char) * pos[X]);
	i = -1;
	while (++i < pos[Y])
	{
		j = -1;
		while (++j < pos[X])
		{
			if (pos_check(i, j, mi))
				out[i][j] = mark[BOX];
			else if (map[i][j] == 0)
				out[i][j] = mark[BLOCK];
			else
				out[i][j] = mark[EMPTY];
		}
	}
	return (out);
}

void	print_map(int **map, int row, int col, char *mark)
{
	char	**answer;
	int		max;
	int		*mi;
	int		pos[2];

	max = get_max(map, row, col);
	mi = get_maxindex(map, row, col, max);
	pos[X] = col;
	pos[Y] = row;
	answer = mk_answer(map, pos, mi, mark);
	print_answer(answer, row, col);
	free(mi);
	free_arr2((void **)answer, row);
}

void	free_arr2(void **arr, int row)
{
	int	i;

	i = -1;
	while (++i < row)
		free(arr[i]);
	free(arr);
}
