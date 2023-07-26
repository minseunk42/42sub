/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:29:11 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 18:01:23 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# define READ (0)
# define WRITE (1)

# ifndef TREE_TYPE
#  define TREE_TYPE

typedef struct s_astree			t_astree;
typedef enum e_tree_type		t_atype;
typedef const struct s_astree	t_ctree;
typedef struct s_cmd			t_cmd;

# endif

typedef struct s_cmd
{
	char	*path;
	char	**argv;
	char	**envp;
	int		in;
	int		out;
	int		builtin;
}	t_cmd;

/* builtin */
int		execute_builtin(const t_cmd *cmd, int is_subshell);

/* cmd */
void	destroy_cmd(t_cmd *cmd);
void	init_cmd(t_cmd *cmd);
void	run_cmd(const t_cmd *cmd, int is_subshell);
void	set_cmd(t_cmd *cmd, t_ctree *argv, t_ctree *path);

/* envp */
void	destroy_envp(void);
int		set_envp(void);

/* execute */
int		executor(t_astree *tree);

/* job */
int		execute_job(const t_astree *tree);

/* pipeline */
int		execute_pipeline(const t_astree *tree, int in, int out);

/* redirections */
int		execute_rd(const t_astree *tree, int in, int out, int is_subshell);
int		heredoc(t_astree *tree);
void	heredoc_fd_close(void);
int		heredoc_open_file(int idx);
int		heredoc_open_file2(int idx);
void	rd_perror(const char *filepath);
int		set_rd_recursive(t_astree *tree, t_cmd *cmd);

/* simple command */
int		execute_simplecmd(t_ctree *tree, int in, int out, int is_subshell);

/* status */
int		ft_wifexited(int stat);
int		ft_wexitstatus(int stat);

/* types */
int		compare_tree_type(int type1, t_atype type2);
int		is_data(const t_astree *tree);
int		is_pipeline(const t_astree *tree);
int		is_redirection(const t_astree *tree);
int		is_stdin(const t_astree *tree);
int		is_stdout(const t_astree *tree);
int		is_stdin_heredoc(const t_astree *tree);
int		is_stdout_append(const t_astree *tree);

#endif /* EXECUTOR_H */
