/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:12:23 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/26 16:09:36 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

int	free_all(char *str, t_token *tokens, t_astree *ast, char *errmsg)
{
	if (str)
		free(str);
	if (tokens != NULL)
		destroy_token_list(tokens);
	if (ast != NULL)
		delete_tree(ast);
	printf("%s", errmsg);
	return (EXIT_FAILURE);
}
