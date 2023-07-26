/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_rd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:29:20 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 15:41:10 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include "tree.h"

int	is_stdin(const t_astree *tree)
{
	return (compare_tree_type(tree->type, AT_TYPE_IN));
}

int	is_stdout(const t_astree *tree)
{
	return (compare_tree_type(tree->type, AT_TYPE_OUT));
}

int	is_stdin_heredoc(const t_astree *tree)
{
	return (compare_tree_type(tree->type, AT_TYPE_HEREDOC));
}

int	is_stdout_append(const t_astree *tree)
{
	return (compare_tree_type(tree->type, AT_TYPE_APPEND));
}
