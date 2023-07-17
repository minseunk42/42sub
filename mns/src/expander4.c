/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:21:12 by gylim             #+#    #+#             */
/*   Updated: 2023/07/15 18:55:39 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env_list.h"
#include "expander.h"
#include "lexer.h"
#include "libft.h"

static char	**expand_split(char *str)
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

char	*concat_words(char **words)
{
	int		i;
	char	*ret;

	i = 0;
	ret = ft_strdup(words[i++]);
	while (words[i] != NULL)
		append(&ret, words[i++]); /* error handler 추가  */
	return (ret);
}

void	destroy_words(char **words)
{
	int	i;

	i = 0;
	while (words[i] != NULL)
		free(words[i++]);
	free(words);
}

char	*expand(t_env_list *list, t_token *tok)
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
			if (words[i][1] == '?')
				expand_exit_status(words, i, 0);
			else
				expand_env(list, words, i);
		}
		i++;
	}
	expanded = concat_words(words);
	destroy_words(words);
	return (expanded);
}
