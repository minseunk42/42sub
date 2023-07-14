/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:56:58 by gylim             #+#    #+#             */
/*   Updated: 2023/07/13 17:28:29 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "readline/readline.h"

int	heredoc(const char *outfile, const char *limiter)
{
	int		input_len;
	int		limiter_len;
	int		out_fd;
	char	*input;

	out_fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (out_fd < 0)
		return (-1);
	limiter_len = ft_strlen(limiter);
	input_len = 0;
	while (1)
	{
		input = readline("> ");
		if (input)
			input_len = ft_strlen(input);
		if (!ft_strncmp(limiter, input, limiter_len) && input_len == limiter_len)
		{
			free(input);
			break ;
		}
		write(out_fd, input, input_len);
		write(out_fd, "\n", 1);
		free(input);
	}
	return (out_fd);
}
