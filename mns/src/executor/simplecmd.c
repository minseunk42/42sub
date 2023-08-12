/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplecmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:18:41 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 20:27:16 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "executor.h"
#include "minishell.h"

int	execute_simplecmd(const t_astree *tree, int in, int out, int is_subshell)
{
	t_cmd	cmd;

	if (tree == NULL)
		return (0);
	init_cmd(&cmd);
	if (in != -1)
		cmd.in = in;
	if (out != -1)
		cmd.out = out;
	set_cmd(&cmd, tree, tree);
	run_cmd(&cmd, is_subshell);
	destroy_cmd(&cmd);
	return (0);
}
