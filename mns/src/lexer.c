/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:44:10 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/14 18:43:13 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

void	mk_rdtok(char *str, t_token **tokens, int *i)
{
	if (str[0] == '<' && str[1] != '<')
		add_token(tokens, create_token(T_TYPE_IN, TQ_TYPE_NONE, "<"));
	else if (str[0] == '>' && str[1] != '>')
		add_token(tokens, create_token(T_TYPE_OUT, TQ_TYPE_NONE, ">"));
	else if (str[0] == '<' && str[1] == '<' && ++(*i))
		add_token(tokens, create_token(T_TYPE_HEREDOC, TQ_TYPE_NONE, "<<"));
	else if (str[0] == '>' && str[1] == '>' && ++(*i))
		add_token(tokens, create_token(T_TYPE_APPEND, TQ_TYPE_NONE, ">>"));
}

void	mk_pptok(char *str, t_token **tokens)
{
	if (str[0] == '|' && str[1] != '|')
		add_token(tokens, create_token(T_TYPE_PIPE, TQ_TYPE_NONE, "|"));
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
	add_token(tokens, create_token(T_TYPE_GENERAL, TQ_TYPE_NONE, temp));
	free(temp);
	--(*idx);
}

int	mk_qttok(char *str, t_token **tokens, int *i)
{
	char	end;
	int		len;
	char	*temp;

	end = *str;
	len = 1;
	while (++(*i) && str[len] && str[len] != end)
		len++;
	if (!str[len])
		return (-1);
	temp = (char *)malloc(sizeof(char) * (len));
	if (len == 1)
		len = 0;
	else
		ft_memcpy(temp, str + 1, len - 1);
	temp[len] = 0;
	if (end == '\'')
		add_token(tokens, create_token(T_TYPE_GENERAL, TQ_TYPE_SQUOTE, temp));
	else
		add_token(tokens, create_token(T_TYPE_GENERAL, TQ_TYPE_DQUOTE, temp));
	free(temp);
	return (0);
}

int	lexer(char *str, t_token **tokens)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (str[++i])
	{
		if (str[i] == '|')
			mk_pptok(&str[i], tokens);
		else if (str[i] == ' ')
			continue ;
		else if (str[i] == '\'' || str[i] == '\"')
			flag = mk_qttok(&str[i], tokens, &i);
		else if (str[i] == '<' || str[i] == '>')
			mk_rdtok(&str[i], tokens, &i);
		else
			mk_nmtok(&str[i], tokens, &i);
		if (flag)
			break ;
	}
	return (flag);
}
