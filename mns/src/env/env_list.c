/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:05:43 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 18:36:52 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "env_list.h"
#include "libft.h"
#include "minishell.h"

/*
 * return value: struct s_env_node on success, NULL on failure.
 */
t_env_node	*env_new_node(const char *key, const char *value)
{
	t_env_node	*new_node;

	if (key == NULL || value == NULL)
		return (NULL);
	new_node = (t_env_node *)malloc(sizeof(t_env_node));
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	new_node->key = ft_strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = ft_strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
	}
	return (new_node);
}

t_env_node	*env_new_node_str(const char *str)
{
	char	*key;
	char	*value;

	key = env_split_key(str);
	if (!key)
		return (NULL);
	value = env_split_value(str);
	if (!value)
		return (NULL);
	return (env_new_node(key, value));
}

int	env_add_rear_node_to_list(t_env_list *list, t_env_node *node)
{
	if (!list || !node)
		return (-1);
	if (list->front == NULL)
	{
		list->front = node;
		list->rear = node;
		list->front->next = list->rear;
		list->rear->next = NULL;
		list->size++;
		return (0);
	}
	list->rear->next = node;
	list->rear = list->rear->next;
	list->size++;
	return (0);
}

/*
 * return value: env_list on success, NULL on failure.
 */
t_env_list	*env_new_list(void)
{
	int					i;
	extern char			**environ;
	t_env_node			*new_node;
	t_env_list			*new_list;

	new_list = (t_env_list *)malloc(sizeof(t_env_list));
	if (new_list == NULL)
		return (NULL);
	new_list->front = NULL;
	new_list->size = 0;
	i = 0;
	while (environ[i] != NULL)
	{
		new_node = env_new_node_str(environ[i]);
		if (new_node == NULL)
		{
			env_destroy_list(new_list);
			return (NULL);
		}
		env_add_rear_node_to_list(new_list, new_node);
		i++;
	}
	return (new_list);
}

int	env_print_list(const t_env_list *list)
{
	t_env_node	*cur;

	cur = list->front;
	while (cur)
	{
		if (printf("%s=%s\n", cur->key, cur->value) < 0)
			return (-1);
		cur = cur->next;
	}
	return (0);
}
