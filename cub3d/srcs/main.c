/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 04:49:00 by minseunk          #+#    #+#             */
/*   Updated: 2023/10/25 10:41:31 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	main(int argc, char **argv)
{
	t_mlx_data	md;

	md.data = run_parse(argc, argv);
	if (!md.data)
		return (-1);
	if (check_path(&md))
		return (free_data(md.data));
	if (init(&md))
		return (free_mlx(&md));
	mlx_hook(md.win_ptr, EVT_KEYE, 0, key_handler, &md);
	mlx_hook(md.win_ptr, EVT_EXIT, 0, fin, &md);
	if (raycast(&md))
		return (free_mlx(&md));
	mlx_loop(md.mlx_ptr);
	return (0);
}
