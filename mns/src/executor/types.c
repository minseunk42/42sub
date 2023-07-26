/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:22:00 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 15:41:10 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "tree.h"

int	compare_tree_type(int type1, t_atype type2)
{
	t_atype	tmp;

	tmp = (type1) & (~(1 << 7));
	return ((tmp & type2) == type2);
}

int	is_data(const t_astree *tree)
{
	return (compare_tree_type(tree->type, AT_TYPE_DATA));
}

int	is_pipeline(const t_astree *tree)
{
	return (compare_tree_type(tree->type, AT_TYPE_PIPE));
}

int	is_redirection(const t_astree *tree)
{
	return (compare_tree_type(tree->type, AT_TYPE_RD));
}
