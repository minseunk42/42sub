/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:49:40 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 14:49:57 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env_list.h"
#include "libft.h"
#include "minishell.h"

int	ft_env(char **argv)
{
	int				argc;
	extern t_gdata	g_data;

	argc = get_argc(argv);
	if (argc != 1)
	{
		ft_printf(2, "minishell: env: too may arguments\n");
		return (EXIT_FAILURE);
	}
	env_print_list(g_data.env_list);
	return (EXIT_SUCCESS);
}
