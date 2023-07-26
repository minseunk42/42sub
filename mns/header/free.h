/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:13:06 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/21 17:25:19 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include <stdio.h>
# include <stdlib.h>
# include "lexer.h"
# include "tree.h"

int	free_all(char *str, t_token *tokens, t_astree *ast, char *errmsg);

#endif