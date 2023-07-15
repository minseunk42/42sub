/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:19:02 by gylim             #+#    #+#             */
/*   Updated: 2023/07/14 17:07:35 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

static char *cut_env(char **str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while ((*str)[i] != '\0' && !ms_check_set((*str)[i], WHITESPACE))
		i++;
	ret = (char *)malloc((i + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		ret[j] = (*str)[j];
		j++;
	}
	ret[j] = '\0';
	*str += i;
	return (ret);
}

static char	*cut_word(char **str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while ((*str)[i] != '\0' && (*str)[i] != '$')
		i++;
	ret = (char *)malloc((i + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		ret[j] = (*str)[j];
		j++;
	}
	ret[j] = '\0';
	*str += i;
	return (ret);
}

char	*get_word(char **str)
{
	if (**str == '$')
		return (cut_env(str));
	else
		return (cut_word(str));
}
