#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct s_cmd
{
    int pipe[2];
    int type[2];
    int prep;
    char **args;
}   t_cmd;

int get_end(t_cmd *cmd, int st, char **av)
{
    int ed;
    int scnt;

    ed = st;
    while (av[ed] && strcmp(";", av[ed]) && strcmp("|", av[ed]))
        ed++;
    if (av[ed] && !strcmp(";", av[ed]))
    {
        while (strcmp(";", av[ed + 1]))
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
            cmt->type[1] = 0;
        av[ed] = 0;
        av[ed - scnt] = 0;
        cmd->prep = cmd->pipe[0];
    }
    return (ed);
}

void executer(t_cmd *cmd, char **env)
{
    pid_t pid;
    int     exc;

    if ((cmd->type[0] == 1 || cmd->type[1] == 1) && pipe(cmd->pipe) == -1)
        fatal
    pid = fork()
    if (pid == -1)
        fatal;
    if (pid == 0)
    {
        if (cmd->type[0] == 1 && dup2(cmd->prep, 0) == -1)
            ftft
        if (cmd->type[1] == 1 && dup2(cmd->pipe[1], 1) == -1)
            ftft
        if ((exc = execve(cmd->args[0], cmd->args, env)) == -1)
            err
        exit(exc);
    }
    else
    {
        waitpid(pid, 0, 0);
        if (cmd->type[0] == 1 || cmd->type[1] == 1)
        {
            close(cmd->pipe[1]);
            if (cmd->type[1] != 1)
                close(cmd->pipe[0])
        }
        if (cmd->type[0] == 1)
            close(cmd->prep);
    }

}
int main(int ac, char **av, char **env)
{
    t_cmd cmd;
    int     i;
    int     st;

    i = 0;
    while (++i < ac)
    {
        st = i;
        i = get_end(&cmd, i, av);
        if (!strcmp("cd", av[st]))
        {
            if (i - st != 2)
                puterr(averr)
            else if(chdir(av[st + 1]) == -1)
            {
        
            }
        }
        else
            executer(&cmd, env);
    }
    return (0);
}