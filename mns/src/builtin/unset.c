/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:54:53 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 14:55:02 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "builtin.h"
#include "env_list.h"
#include "minishell.h"

int	ft_unset(char **argv)
{
	int				i;
	extern t_gdata	g_data;

	i = 1;
	while (argv[i] != NULL)
	{
		env_unset(g_data.env_list, argv[i]);
		i++;
	}
	return (0);
}
