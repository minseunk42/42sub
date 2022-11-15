/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 05:43:14 by sanghyep          #+#    #+#             */
/*   Updated: 2022/10/09 22:02:37 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_from_top(int **table, int *view, int n)
{
	int	row;
	int	col;
	int	able_to_see;
	int	tallest;

	col = 0;
	while (col < n)
	{
		able_to_see = 1;
		tallest = table[0][col];
		row = 1;
		while (row < n)
		{
			if (table[row][col] > tallest)
			{
				able_to_see++;
				tallest = table[row][col];
			}
			row++;
		}
		if (*(view + col) != able_to_see)
			return (0);
		col++;
	}
	return (1);
}

int	check_from_bottom(int **table, int *view, int n)
{
	int	row;
	int	col;
	int	able_to_see;
	int	tallest;

	col = 0;
	while (col < n)
	{
		able_to_see = 1;
		tallest = table[n - 1][col];
		row = n - 2;
		while (row > -1)
		{
			if (table[row][col] > tallest)
			{
				able_to_see++;
				tallest = table[row][col];
			}
			row--;
		}
		if (*(view + col) != able_to_see)
			return (0);
		col++;
	}
	return (1);
}

int	check_from_left(int **table, int *view, int n)
{
	int	row;
	int	col;
	int	able_to_see;
	int	tallest;

	row = 0;
	while (row < n)
	{
		able_to_see = 1;
		tallest = table[row][0];
		col = 1;
		while (col < n)
		{
			if (table[row][col] > tallest)
			{
				able_to_see++;
				tallest = table[row][col];
			}
			col++;
		}
		if (*(view + row) != able_to_see)
			return (0);
		row++;
	}
	return (1);
}

int	check_from_right(int **table, int *view, int n)
{
	int	row;
	int	col;
	int	able_to_see;
	int	tallest;

	row = 0;
	while (row < n)
	{
		able_to_see = 1;
		tallest = table[row][n - 1];
		col = n - 2;
		while (col > -1)
		{
			if (table[row][col] > tallest)
			{
				able_to_see++;
				tallest = table[row][col];
			}
			col--;
		}
		if (*(view + row) != able_to_see)
			return (0);
		row++;
	}
	return (1);
}

int	is_board_perfect(int **table, int *view)
{
	int	offset;

	offset = view[0];
	view++;
	if (!check_from_top(table, view, offset))
		return (0);
	if (!check_from_bottom(table, view + offset, offset))
		return (0);
	if (!check_from_left(table, view + (2 * offset), offset))
		return (0);
	if (!check_from_right(table, view + (3 * offset), offset))
		return (0);
	return (1);
}
