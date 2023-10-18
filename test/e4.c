#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct s_cmd
{
    int pipe[2];
    int type[2];
    int prep;
    char **args;
}   t_cmd;

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int puterr(char *str)
{
    write(2, str, ft_strlen(str));
    return (1);
}

void   ftft(void)
{
    puterr("error: fatal\n");
    exit(1);
}


void    executer(t_cmd *cmd, char **env)
{
    pid_t   pid;
    int     exc;

    if ((cmd->type[0] == 1 || cmd->type[1] == 1) && pipe(cmd->pipe) == -1)
        ftft();
    if ((pid = fork()) == -1)
        ftft();
    if (pid == 0)
    {
        if (cmd->type[0] == 1 && dup2(cmd->prep, 0) == -1)
            ftft();
        if (cmd->type[1] == 1 && dup2(cmd->pipe[1], 1) == -1)
            ftft();
        if ((exc = execve(cmd->args[0], cmd->args, env)) == -1)
        {
            puterr("error: cannot execute ");
            puterr(cmd->args[0]);
            puterr("\n");
        }
        exit(exc);
    }
    else
    {
        waitpid(pid, 0, 0);
        if (cmd->type[0] == 1 || cmd->type[1] == 1)
        {
            close(cmd->pipe[1]);
            if (cmd->type[1] != 1)
                close(cmd->pipe[0]);
        }
        if (cmd->type[0] == 1)
            close(cmd->prep);
    }
}

int get_end(t_cmd *cmd, int st, char **av)
{
    int ed;
    int scnt;

    ed = st;
    scnt = 0;
    while (av[ed] && strcmp(";", av[ed]) && strcmp("|", av[ed]))
        ed++;
    if (av[ed] && !strcmp(";", av[ed]))
    {
        while (!strcmp(";", av[ed + 1]))
        {
            ed++;
            scnt++;
        }
    }
    if (ed > st)
    {
        cmd->args = &av[st];
        cmd->type[0] = cmd->type[1];
        if (av[ed] && !strcmp("|", av[ed]))
            cmd->type[1] = 1;
        else
            cmd->type[1] = 0;
        av[ed] = 0;
        av[ed - scnt] = 0;
        cmd->prep = cmd->pipe[0];
    }
    return (ed);
}

int main(int ac, char **av, char **env)
{
    t_cmd   cmd;
    int     i;
    int     st;

    i = 0;
    while (++i < ac)
    {
        st = i;
        i = get_end(&cmd, st, av);
        if (!strcmp(av[st], "cd"))
        {
            if (i - st != 2)
                puterr("error: cd: bad arguments\n");
            else if (chdir(av[st + 1]) == -1)
            {
                puterr("error: cd: cannot change directory to ");
                puterr(av[st + 1]);
                puterr("\n");
            }
        }
        else
            executer(&cmd, env);
    }
}