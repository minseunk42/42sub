/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:33:06 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 18:38:07 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "env_list.h"
#include "libft.h"
#include "minishell.h"

static int	is_valid_id(char *str)
{
	int	i;
	int	is_num_possible;

	is_num_possible = 0;
	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (!(str[i] == '_' || ft_isalnum(str[i])))
			return (0);
		if (!is_num_possible && ft_isdigit(str[i]))
			return (0);
		if (ft_isalpha(str[i]) || str[i] == '_')
			is_num_possible = 1;
		i++;
	}
	if (str[i] != '=')
		return (0);
	return (!ms_check_set(str[i + 1], WHITESPACE));
}

int	env_export(t_env_list *list, char *str)
{
	size_t		len;
	char		*key;
	char		*value;
	t_env_node	*cur;

	if (!is_valid_id(str))
		return (-1);
	key = env_split_key(str);
	value = env_split_value(str);
	len = ft_strlen(key);
	cur = list->front;
	while (cur)
	{
		if (!ft_strncmp(cur->key, key, len) && len == ft_strlen(cur->key))
		{
			free(key);
			free(cur->value);
			cur->value = value;
			return (0);
		}
		cur = cur->next;
	}
	return (env_add_rear_node_to_list(list, env_new_node(key, value)));
}

char	*env_get_value_or_null(t_env_list *list, const char *key)
{
	char		*ret;
	size_t		len;
	t_env_node	*cur;

	len = ft_strlen(key);
	cur = list->front;
	while (cur != NULL)
	{
		if (!ft_strncmp(key, cur->key, len) && len == ft_strlen(cur->key))
		{
			ret = ft_strdup(cur->value);
			if (ret == NULL)
			{
				perror("minishell");
				exit(EXIT_FAILURE);
			}
			return (ret);
		}
		cur = cur->next;
	}
	return (NULL);
}

t_env_node	*env_search_node(t_env_list *list, const char *key)
{
	size_t		len;
	t_env_node	*cur;

	len = ft_strlen(key);
	cur = list->front;
	while (cur != NULL)
	{
		if (!ft_strncmp(cur->key, key, len) && len == ft_strlen(cur->key))
		{
			return (cur);
		}
		cur = cur->next;
	}
	return (NULL);
}

void	env_destroy_list(t_env_list *list)
{
	t_env_node	*cur;
	t_env_node	*next;

	cur = list->front;
	next = NULL;
	while (cur != NULL)
	{
		next = cur->next;
		free(cur->key);
		free(cur->value);
		free(cur);
		cur = next;
	}
	free(list);
}
