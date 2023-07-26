/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:25:13 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 19:02:41 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env_list.h"
#include "executor.h"
#include "libft.h"
#include "minishell.h"
#include "tree.h"

static size_t	get_total_len(t_env_node *node)
{
	return (ft_strlen(node->key) + ft_strlen(node->value) + 1);
}

static char	*fill_string(t_env_node *node, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (node->key[i] != '\0')
	{
		str[i] = node->key[i];
		i++;
	}
	str[i] = '=';
	i++;
	j = 0;
	while (node->value[j] != '\0')
	{
		str[i] = node->value[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

static char	*get_envp_string(t_env_node *node)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (get_total_len(node) + 1));
	if (res == NULL)
		return (NULL);
	return (fill_string(node, res));
}

void	destroy_envp(void)
{
	int				i;
	char			**internal_envp;

	internal_envp = g_data.internal_envp;
	i = 0;
	while (internal_envp[i] != NULL)
	{
		free(internal_envp[i]);
		i++;
	}
	free(internal_envp);
	g_data.internal_envp = NULL;
}

int	set_envp(void)
{
	t_env_node		*node;
	int				i;
	int				size;

	size = g_data.env_list->size;
	g_data.internal_envp = (char **)malloc(sizeof(char *) * (size + 1));
	if (g_data.internal_envp == NULL)
		return (-1);
	i = 0;
	node = g_data.env_list->front;
	while (i < size && node != NULL)
	{
		g_data.internal_envp[i] = get_envp_string(node);
		if (g_data.internal_envp[i] == NULL)
		{
			destroy_envp();
			return (-1);
		}
		node = node->next;
		i++;
	}
	g_data.internal_envp[i] = NULL;
	return (0);
}
