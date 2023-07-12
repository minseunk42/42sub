/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:44:10 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/12 10:47:53 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*to;
	unsigned char	*from;

	if (!dst && !src)
		return (NULL);
	if (n == 0 || dst == src)
		return (dst);
	i = 0;
	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*res;

	res = NULL;
	len = ft_strlen(s1);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
	{
		return (NULL);
	}
	ft_memcpy(res, s1, len);
	res[len] = '\0';
	return (res);
}

void	mk_rdtok(char **str, t_token **token)
{
	if (*str[0] == '<' && *str[1] != '<')
	{
		(*token)->type = TT_RDL;
		(*token)->data = ft_strdup("<");
	}
	else if (*str[0] == '>' && *str[1] != '>')
	{
		(*token)->type = TT_RDR;
		(*token)->data = ft_strdup(">");
	}
	else if (*str[0] == '<' && *str[1] == '<' && (*str)++)
	{
		(*token)->type = TT_RDLL;
		(*token)->data = ft_strdup("<<");
	}
	else if (*str[0] == '>' && *str[1] == '>' && (*str)++)
	{
		(*token)->type = TT_RDRR;
		(*token)->data = ft_strdup(">>");
	}
	(*token)->next = 0;
}

void	mk_pptok(char **str, t_token **token)
{
	if (*str[0] == '|' && *str[1] != '|')
	{
		(*token)->type = TT_PIPE;
		(*token)->data = ft_strdup("|");
	}
	(*token)->next = 0;
}

void	mk_nmtok(char **str, t_token **token)
{
	int		len;
	char	*temp;
	int		i;

	len = 0;
	while ((*str)[len])
	{
		if ((*str)[len] == '\'' || (*str)[len] == '\"' || (*str)[len] == '|'
			|| (*str)[len] == '<' || (*str)[len] == '>' || (*str)[len] == ' ')
			break ;
		len++;
	}
	temp = (char *)malloc(sizeof(char) * len + sizeof(char));
	i = 0;
	while (i < len)
	{
		temp[i++] = **str;
		(*str)++;
	}
	temp[i] = 0;
	(*token)->type = TT_NORM;
	(*token)->next = 0;
	(*token)->data = temp;
	free(temp);
}

void	mk_qttok(char **str, t_token **token)
{
	char	end;
	int		len;
	char	*temp;

	end = **str;
	len = 0;
	while ((*str)[len] != end)
		len++;
	temp = (char *)malloc(sizeof(char) * len + sizeof(char));
	len = 0;
	while (*(++(*str)) != end)
		temp[len++] = **str;
	temp[len] = 0;
	(*token)->type = TT_NORM;
	(*token)->next = 0;
	(*token)->data = temp;
	free(temp);
}

void	lexer(char *str, t_token **tokens)
{
	int		i;
	t_token	*token;

	i = 0;
	while (str[i])
	{
		printf("%c", str[i]);
		token = (t_token *)malloc(sizeof(t_token));
		*tokens = token;
		if (str[i] == '|')
			mk_pptok(&str, &token);
		else if (str[i] == '\'' || str[i] == '\"')
			mk_qttok(&str, &token);
		else if (str[i] == '<' || str[i] == '>')
			mk_rdtok(&str, &token);
		else
			mk_nmtok(&str, &token);
		*tokens = (*tokens)->next;
		i++;
	}
}


int main(int ac, char **av)
{
	t_token	*tokens;

	lexer(av[1], &tokens);
	while (tokens)
	{
		printf("%s\n", tokens->data);
		tokens = tokens->next;
	}
}
