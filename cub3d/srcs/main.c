/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 04:49:00 by minseunk          #+#    #+#             */
/*   Updated: 2023/10/21 00:36:15 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	main(int argc, char **argv)
{
	t_mlx_data	md;

	md.data = run_parse(argc, argv);
	if (!md.data)
		return (-1);
	if (init(&md))
		return (-1);
	mlx_hook(md.win_ptr, EVT_KEYE, 0, key_handler, &md);
	mlx_hook(md.win_ptr, EVT_EXIT, 0, fin, &md);
	if (raycast(&md))
		return (-1);
	mlx_loop(md.mlx_ptr);
	return (0);
}
