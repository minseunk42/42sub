#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct s_cmd
{
	int		pipe[2];
	int		type[2];
	int		prev_pipe;
	char	**args;
}	t_cmd;

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_fatal(void)
{
	write(2, "error: fatal\n", ft_strlen("error: fatal\n"));
	exit(1);
}

int		ft_list_end(t_cmd *cmd, int start, char **argv)
{
	int		end;
	int		semicolon_counter;

	semicolon_counter = 0;
	end = start;
	while (argv[end] && strcmp(argv[end], "|") && strcmp(argv[end], ";"))
		end++;
	if (argv[end] && strcmp(argv[end], ";") == 0)
    {
		while (strcmp(argv[end + 1], ";") == 0)
		{
			end++;
			semicolon_counter++;
		}
    }
	if (end - start > 0)
	{
		cmd->args = &argv[start];
		cmd->type[0] = cmd->type[1];
		if (argv[end] && strcmp(argv[end], "|") == 0)
			cmd->type[1] = 1;
		else
			cmd->type[1] = 0;
		argv[end] = NULL;
		argv[end - semicolon_counter] = NULL;
		cmd->prev_pipe = cmd->pipe[0];
	}
	return (end);
}

void	ft_exec_cmd(t_cmd *cmd, char **env)
{
	pid_t	pid;
	int		ex;

	if ((cmd->type[0] == 1 || cmd->type[1] == 1) && pipe(cmd->pipe) == -1)
		ft_fatal();
	if ((pid = fork()) == -1)
		ft_fatal();
	if (pid == 0)
	{
		if (cmd->type[0] == 1 && dup2(cmd->prev_pipe, 0) == -1)
			ft_fatal();
		if (cmd->type[1] == 1 && dup2(cmd->pipe[1], 1) == -1)
			ft_fatal();
		if ((ex = execve(cmd->args[0], cmd->args, env)) == -1)
		{
			write(2, "error: cannot execute ", ft_strlen("error: cannot execute "));
			write(2, cmd->args[0], ft_strlen(cmd->args[0]));
			write(2, "\n", 1);
		}
		exit(ex);
	}
	else
	{
		waitpid(pid, NULL, 0);
		if (cmd->type[0] == 1 || cmd->type[1] == 1)
		{
			close(cmd->pipe[1]);
			if (cmd->type[1] != 1)
				close(cmd->pipe[0]);
		}
		if (cmd->type[0] == 1)
			close(cmd->prev_pipe);
	}
}

int		main(int argc, char **argv, char **env)
{
	t_cmd	cmd;
	int		i;
	int		start;

	i = 1;
	while (i < argc)
	{
		start = i;
		i = ft_list_end(&cmd, start, argv);
		if (strcmp(argv[start], "cd") == 0)
		{
			if (i - start != 2)
				write(2, "error: cd: bad arguments\n", ft_strlen("error: cd: bad arguments\n"));
			else if (chdir(argv[start + 1]) == -1)
			{
				write(2, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
				write(2, argv[start + 1], ft_strlen(argv[start + 1]));
				write(2, "\n", 1);
			}
		}
		else
			ft_exec_cmd(&cmd, env);
		i++;
	}
	return (0);
}
