/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:09:19 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/21 15:47:08 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

typedef enum e_tree_type
{
	AT_TYPE_DATA	= (1 << 0),
	AT_TYPE_PIPE	= (1 << 1),
	AT_TYPE_OUT		= (1 << 2),
	AT_TYPE_APPEND	= (1 << 3),
	AT_TYPE_IN		= (1 << 4),
	AT_TYPE_HEREDOC	= (1 << 5),
	AT_TYPE_RD		= (1 << 6)
}	t_atype;

typedef struct s_astree
{
	int				type;
	char			*data;
	struct s_astree	*left;
	struct s_astree	*right;
}	t_astree;

int			add_tree(t_astree *root, t_astree *left, t_astree *right);
int			create_node(t_astree *node, t_atype atype, char *data);
int			delete_tree(t_astree *node);

#endif