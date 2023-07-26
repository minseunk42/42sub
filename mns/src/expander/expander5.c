/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:39:40 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 15:44:45 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "expander.h"
#include "lexer.h"
#include "libft.h"

static int	expand_exit_status_error1(char **words)
{
	destroy_words(words);
	return (-1);
}

static int	expand_exit_status_error2(char **words, char *str)
{
	destroy_words(words);
	free(str);
	return (-1);
}

static void	expand_exit_status_declutter(char **words, char *str)
{
	destroy_words(words);
	free(str);
}

int	expand_exit_status(char **words, int idx, int exit_status)
{
	int		i;
	char	*expanded;
	char	*status;
	char	**tmp;

	tmp = ft_split(words[idx], '?');
	if (tmp == NULL)
		return (-1);
	status = ft_itoa(exit_status);
	if (status == NULL)
		return (expand_exit_status_error1(tmp));
	expanded = ft_strdup(status);
	if (expanded == NULL)
		return (expand_exit_status_error2(tmp, status));
	free(status);
	i = 1;
	while (tmp[i] != NULL)
	{
		if (!append(&expanded, tmp[i++]))
			return (expand_exit_status_error2(tmp, expanded));
		i++;
	}
	expand_exit_status_declutter(tmp, words[idx]);
	words[idx] = expanded;
	return (0);
}
