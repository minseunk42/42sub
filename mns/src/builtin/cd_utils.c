/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:47:56 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 14:48:08 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "env_list.h"
#include "minishell.h"

static int	add_oldpwd_to_envlist(t_env_list *list, const char *cwd)
{
	t_env_node	*node;

	node = env_new_node("OLDPWD", cwd);
	if (node == NULL)
		return (-1);
	return (env_add_rear_node_to_list(list, node));
}

static int	update_oldpwd(void)
{
	extern t_gdata		g_data;
	t_env_node			*node;
	char				*cwd;

	node = env_search_node(g_data.env_list, "OLDPWD");
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		return (-1);
	if (node == NULL)
		return (add_oldpwd_to_envlist(g_data.env_list, cwd));
	free(node->value);
	node->value = cwd;
	return (0);
}

static int	add_pwd_to_envlist(t_env_list *list, const char *cwd)
{
	t_env_node	*node;

	node = env_new_node("PWD", cwd);
	if (node == NULL)
		return (-1);
	return (env_add_rear_node_to_list(list, node));
}

static int	update_pwd(void)
{
	extern t_gdata		g_data;
	t_env_node			*node;
	char				*cwd;

	node = env_search_node(g_data.env_list, "PWD");
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		return (-1);
	if (node == NULL)
		return (add_pwd_to_envlist(g_data.env_list, cwd));
	free(node->value);
	node->value = cwd;
	return (0);
}

int	change_directory(const char *path)
{
	if (update_oldpwd() == -1)
		return (-1);
	if (chdir(path) == -1)
		return (-1);
	if (update_pwd() == -1)
		return (-1);
	return (0);
}
