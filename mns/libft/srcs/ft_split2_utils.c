/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:09:18 by gylim             #+#    #+#             */
/*   Updated: 2023/06/29 19:11:16 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ps_check_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static void	free_arr(char **arr, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*get_word(char const *s, const char *set, int *word_len)
{
	char	*word;

	*word_len = 0;
	word = NULL;
	while (*s && ps_check_set(*s, set))
		s++;
	if (*s)
	{
		word = (char *)s;
		while (*s && !ps_check_set(*s, set))
		{
			++s;
			++*word_len;
		}
	}
	return (word);
}

int	ps_count_words(char const *s, char const *set)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s && ps_check_set(*s, set))
			s++;
		if (*s)
		{
			cnt++;
			while (*s && !ps_check_set(*s, set))
				s++;
		}
	}
	return (cnt);
}

char	**ps_cut(char **arr, const char *s, const char *set, int word_cnt)
{
	char	*word;
	int		i;
	int		len;

	i = 0;
	while (*s && i < word_cnt)
	{
		word = get_word(s, set, &len);
		if (!word)
			break ;
		arr[i] = malloc((len + 1) * sizeof(char));
		if (arr[i] == NULL)
		{
			free_arr(arr, i);
			return (NULL);
		}
		ft_strlcpy(arr[i], word, len + 1);
		i++;
		s = word + len;
	}
	arr[i] = NULL;
	return (arr);
}
