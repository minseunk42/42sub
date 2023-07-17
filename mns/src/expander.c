/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:06:20 by gylim             #+#    #+#             */
/*   Updated: 2023/07/15 18:54:26 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env_list.h"
#include "expander.h"
#include "lexer.h"
#include "libft.h"
#include "minishell.h"

int	expander(t_env_list *list, t_token *tok)
{
	char	*expanded;

	while (tok != NULL)
	{
		if (tok->data == NULL || tok->data[0] == '\0')
			;
		else if (tok->qtype != TQ_TYPE_SQUOTE)
		{
			expanded = expand(list, tok);
			free(tok->data);
			tok->data = expanded;
			expanded = NULL;
		}
		tok = tok->next;
	}
	return (0);
}
