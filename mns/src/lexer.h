/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:44:49 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/13 20:28:44 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum e_token_type
{
	T_TYPE_GENERAL,
	T_TYPE_PIPE,
	T_TYPE_OUT,
	T_TYPE_APPEND,
	T_TYPE_IN,
	T_TYPE_HEREDOC
}	t_ttype;

typedef enum e_token_quote_type
{
	TQ_TYPE_NONE,
	TQ_TYPE_DQUOTE,
	TQ_TYPE_SQUOTE
}	t_qtype;

typedef struct s_token
{
	t_ttype			type;
	t_qtype			qtype;
	char			*data;
	struct s_token	*next;
}	t_token;

void	add_token(t_token **lst, t_token *new);
t_token *create_token(t_ttype type, char *data);
t_token	*get_last_token(t_token *lst);
void    lexer(char *str, t_token **tokens);

#endif /* LEXER_H */
