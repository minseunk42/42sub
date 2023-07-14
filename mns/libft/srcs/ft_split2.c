/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:07:36 by gylim             #+#    #+#             */
/*   Updated: 2023/06/29 19:11:34 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

int		ps_count_words(const char *s, const char *set);
char	**ps_cut(char **arr, const char *s, const char *set, int word_cnt);

char	**ft_split2(const char *s, const char *set)
{
	int		word_cnt;
	char	**arr;

	if (s == NULL)
		return (NULL);
	word_cnt = ps_count_words(s, set);
	arr = (char **)malloc((word_cnt + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	return (ps_cut(arr, s, set, word_cnt));
}
