/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:17:00 by gylim             #+#    #+#             */
/*   Updated: 2023/07/15 18:55:39 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "expander.h"
#include "minishell.h"

static void	dollarsign_counter(const char *str, int *i, int *cnt, int *is_env)
{
	*is_env = 1;
	++*cnt;
	++*i;
	if (str[*i] == '$')
	{
		++*i;
		return ;
	}
	while (str[*i] != '\0' && !ms_check_set(str[*i], EXPANDER_CHAR_SET))
		++*i;
}

static void	general_counter(int *i, int *cnt, int *is_env)
{
	if (*i == 0 || *is_env == 1)
		++*cnt;
	if (*is_env == 1)
		*is_env = 0;
	++*i;
}

int	get_word_cnt(const char *str)
{
	int	i;
	int	cnt;
	int	is_env;

	is_env = 0;
	cnt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			dollarsign_counter(str, &i, &cnt, &is_env);
		else
			general_counter(&i, &cnt, &is_env);
	}
	return (cnt);
}
