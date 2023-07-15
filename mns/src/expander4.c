/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:21:12 by gylim             #+#    #+#             */
/*   Updated: 2023/07/14 17:16:34 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env_list.h"
#include "lexer.h"
#include "libft.h"

char	*get_word(char **str);
int		get_word_cnt(const char *str);

static char **expand_split(char *str)
{
	int		i;
	int		word_cnt;
	char	**ret;

	word_cnt = get_word_cnt(str);
	ret = (char **)malloc((word_cnt + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		ret[i] = get_word(&str); /* error handler 추가할 것. */
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

static void	expand_env(t_env_list *list, char **words, int idx)
{
	char	*expanded;

	expanded = env_get_value_or_null(list, words[idx] + 1);
	if (expanded == NULL)
		expanded = ft_strdup("");
	free(words[idx]);
	words[idx] = expanded;
}

char	*expand_double_quote(t_env_list *list, t_token *tok)
{
	int		i;
	char	*expanded;
	char	**words;

	words = expand_split(tok->data);
	i = 0;
	while (words[i] != NULL)
	{
		if (words[i][0] == '$' && words[i][1] != '\0')
		{
			expand_env(list, words, i);
		}
		i++;
	}
	expanded = ft_strdup(words[0]);
	i = 1;
	while (words[i] != NULL)
	{
		append(&expanded, words[i]);
		i++;
	}
	return (expanded);
}
