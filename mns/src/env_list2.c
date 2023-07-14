/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:28:35 by gylim             #+#    #+#             */
/*   Updated: 2023/07/12 16:28:25 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env_list.h"
#include "libft.h"
#include "minishell.h"

char	*env_split_key(const char *str)
{
	int		i;
	int		len;
	char	*ret;

	if (str == NULL)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '=')
		len++;
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*env_split_value(const char *str)
{
	int		i;
	int		len;
	char	*ret;
	char	*value;

	if (str == NULL)
		return (NULL);
	value = ft_strchr(str, '=');
	value++;
	len = ft_strlen(value);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = value[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static void	env_delete_pair(t_env_list *list, t_env_node *cur, t_env_node *prev)
{
	if (cur == list->front)
		list->front = cur->next;
	if (cur == list->rear)
		list->rear = prev;
	if (prev)
		prev->next = cur->next;
	free(cur->key);
	free(cur->value);
	free(cur);
	list->size--;
}

void	env_unset(t_env_list *list, const char *key)
{
	size_t		len;
	t_env_node	*prev;
	t_env_node	*cur;

	len = ft_strlen(key);
	prev = NULL;
	cur = list->front;
	while (cur)
	{
		if (!ft_strncmp(cur->key, key, len) && ft_strlen(cur->key) == len)
		{
			env_delete_pair(list, cur, prev);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}
