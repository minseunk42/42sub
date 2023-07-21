/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:12:23 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/21 17:25:35 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

int	free_all(char *str, t_token *tokens, t_astree *ast, char *errmsg)
{
	if (str)
		free(str);
	destroy_token_list(tokens);
	delete_tree(ast);
	printf("%s", errmsg);
	return (EXIT_FAILURE);
}
