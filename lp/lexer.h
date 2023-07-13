/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:44:49 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/11 20:19:42 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

typedef struct s_token
{
    int             type;
	char            *data;
	struct s_token  *next;
}	t_token;

# define TT_NORM 0
# define TT_PIPE 1
# define TT_RDRR 2
# define TT_RDLL 3
# define TT_RDR 4
# define TT_RDL 5

#endif