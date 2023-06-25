/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:46:15 by minseunk          #+#    #+#             */
/*   Updated: 2023/06/25 15:02:39 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void free_map(t_fdf *fdf)
{
    int i;

    i = -1;
    while (++i < fdf->row)
        free(fdf->map[i]);
    free(fdf->map);        
}

int	free_strs(char **strs)
{
	int	i;

	if (!strs)
		return (-1);
	i = -1;
	while (strs[++i])
		free(strs[i])
	free(strs);
	return (-1);
}