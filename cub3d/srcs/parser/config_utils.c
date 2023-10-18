/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:24:15 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/16 22:38:44 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parse.h"

int	check_id(const char *s, int *idx)
{
	if (!s)
		return (0);
	*idx = 0;
	while (*(s + *idx) && check_whitespace(*(s + *idx)))
		*idx += 1;
	if (!(*(s + *idx)))
		return (0);
	if (!(*s + *idx + 1))
		return (0);
	if (*(s + *idx) == 'N' && (*(s + *idx + 1) == 'O'))
		return (1);
	if (*(s + *idx) == 'S' && (*(s + *idx + 1) == 'O'))
		return (2);
	if (*(s + *idx) == 'W' && (*(s + *idx + 1) == 'E'))
		return (3);
	if (*(s + *idx) == 'E' && (*(s + *idx + 1) == 'A'))
		return (4);
	if (*(s + *idx) == 'F')
		return (5);
	if (*(s + *idx) == 'C')
		return (6);
	return (0);
}

char	*cub_substr(char *s, unsigned int start, size_t len)
{
	char		*ret_str;
	size_t		i;
	size_t		real_len;

	i = 0;
	real_len = 0;
	while (real_len + start < ch_strlen(s) && real_len < len)
		real_len++;
	ret_str = (char *)malloc(sizeof(char) * (real_len + 1));
	if (!ret_str)
		return (NULL);
	while (i < real_len)
	{
		*(ret_str + i) = *(s + start + i);
		i++;
	}
	*(ret_str + i) = '\0';
	free(s);
	s = NULL;
	return (ret_str);
}
