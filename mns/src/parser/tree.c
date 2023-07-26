/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:09:09 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/26 19:00:18 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "libft.h"

int	add_tree(t_astree *root, t_astree *left, t_astree *right)
{
	root->left = left;
	root->right = right;
	return (0);
}

int	create_node(t_astree *node, t_atype atype, char *data)
{	
	node->type = 0;
	node->type |= atype;
	if (data)
	{
		node->data = ft_strdup(data);
		node->type |= AT_TYPE_DATA;
	}
	return (0);
}

int	delete_tree(t_astree *node)
{
	if (!node)
		return (-1);
	if (node->type & AT_TYPE_DATA)
		free(node->data);
	delete_tree(node->left);
	delete_tree(node->right);
	free(node);
	return (0);
}

t_astree	*get_lastnode(t_astree *node)
{
	t_astree	*temp;

	if (!node)
		return (0);
	temp = node;
	while (temp->right)
		temp = temp->right;
	return (temp);
}
