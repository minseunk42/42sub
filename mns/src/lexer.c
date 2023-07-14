/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:44:10 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/13 19:57:13 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

void	mk_rdtok(char *str, t_token **tokens, int *i)
{
	if (str[0] == '<' && str[1] != '<')
		add_token(tokens, create_token(T_TYPE_IN, "<"));
	else if (str[0] == '>' && str[1] != '>')
		add_token(tokens, create_token(T_TYPE_OUT, ">"));
	else if (str[0] == '<' && str[1] == '<' && ++(*i))
		add_token(tokens, create_token(T_TYPE_HEREDOC, "<<"));
	else if (str[0] == '>' && str[1] == '>' && ++(*i))
		add_token(tokens, create_token(T_TYPE_APPEND, ">>"));
}

void	mk_pptok(char *str, t_token **tokens)
{
	if (str[0] == '|' && str[1] != '|')
		add_token(tokens, create_token(T_TYPE_PIPE, "|"));
}

void	mk_nmtok(char *str, t_token **tokens, int *idx)
{
	int		len;
	char	*temp;

	len = -1;
	while (str[++len] && ++(*idx))
	{
		if (str[len] == '\'' || str[len] == '\"' || str[len] == '|'
			|| str[len] == '<' || str[len] == '>' || str[len] == ' ')
			break ;
	}
	temp = (char *)malloc(sizeof(char) * (len + 1));
	ft_memcpy(temp, str, len);
	temp[len] = 0;
	add_token(tokens, create_token(T_TYPE_GENERAL, temp));
	free(temp);
	--(*idx);
}

void	mk_qttok(char *str, t_token **tokens, int *i)
{
	char	end;
	int		len;
	char	*temp;

	end = *str;
	len = 1;
	while (++(*i) && str[len] != end)
		len++;
	len++;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	ft_memcpy(temp, str, len);
	temp[len] = 0;
	add_token(tokens, create_token(T_TYPE_GENERAL, temp));
	free(temp);
}

void	lexer(char *str, t_token **tokens)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '|')
			mk_pptok(&str[i], tokens);
		else if (str[i] == ' ')
			continue ;
		else if (str[i] == '\'' || str[i] == '\"')
			mk_qttok(&str[i], tokens, &i);
		else if (str[i] == '<' || str[i] == '>')
			mk_rdtok(&str[i], tokens, &i);
		else
			mk_nmtok(&str[i], tokens, &i);
	}
}
