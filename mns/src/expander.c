/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:06:20 by gylim             #+#    #+#             */
/*   Updated: 2023/07/14 16:55:31 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env_list.h"
#include "lexer.h"
#include "libft.h"
#include "minishell.h"

char	*expand_double_quote(t_env_list *list, t_token *tok);

int expander(t_env_list *list, t_token *tok)
{
	char	*expanded;

	while (tok != NULL)
	{
		//if (tok->qtype == TQ_TYPE_DQUOTE)
		{
			expanded = expand_double_quote(list, tok);
			free(tok->data);
			tok->data = expanded;
			expanded = NULL;	
		}
		tok = tok->next;
	}
	return (0);
}
