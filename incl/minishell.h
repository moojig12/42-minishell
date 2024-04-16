/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:44:09 by nmandakh          #+#    #+#             */
/*   Updated: 2024/04/16 19:28:11 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SUCCESS 0
# define FAILURE -1

# define TRUE 1
# define FALSE 0

# define STDIN 0
# define STDOUT 1
# define STDERR 2

#define _POSIX_SOURCE 1

# include <stdio.h>				// printf
# include <readline/readline.h>	// readline
# include <readline/history.h>	// rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history
# include <stdlib.h>			// malloc, free, exit
# include <unistd.h>			// access, fork, execve, getcwd, chdir, close, read, write, pipe, dup, dup2, wait, waitpid
# include <fcntl.h>				// open
# include <signal.h>			// signal, sigaction, sigemptyset, sigaddset, kill
# include <sys/types.h>			// wait, waitpid, fork, access, open, stat, lstat, fstat, dup, dup2, pipe, opendir, readdir, closedir
# include <sys/wait.h>			// wait, waitpid, wait3, wait4
# include <sys/stat.h>			// stat, lstat, fstat, unlink
# include <dirent.h>			// opendir, readdir, closedir
# include <string.h>			// strerror
# include <errno.h>				// perror
# include <termios.h>			// tcsetattr, tcgetattr
# include <unistd.h>			// isatty, ttyname, ttyslot, ioctl
# include <curses.h>			// tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <stdlib.h>			// getenv
# include <limits.h>
# include "libft.h"

//	Type -> 0 == Command, 1 == Argument, 2 == Operator
typedef struct s_token {
	char			*value;
	int				type;
	struct 	s_token *next;
	struct	s_token *prev;
}	t_token;

typedef struct s_hist {
	char			*value;
	struct s_hist	*prev;
	struct s_hist	*next;
}	t_hist;

// main.c
int		main(int argc, char** argv, char **env);

// tokenization.c
// int	count_words(char *input);
void	convert_to_token(t_token **tokens, char *input, int word);
int		lexical_analysis(t_token **tokens, char *input);
void	print_tokens(t_token *token);

// exec.c
int		exec_wrapper(char **cmd, char **env);
int		count_token(t_token *tokens);
char	**tokens_to_args(t_token *tokens);
int		execute(t_token	*tokens, char **env);
int		fork_program(char *pgr_path, char **argv, char **env);

// utils.c
int		is_whitespace(char c);
t_token	*last_node(t_token *node);
void	add_to_back(t_token **tokens, t_token *new); //FIX: new is a reserved keyword
void	skip_letters(char *input, int *i);
void	skip_operator(char *input, int *i);
void	skip_space(char *input, int *i);
int		count_letters(char *input);

// parse.c
int		check_operator(char *input, int index, int mode);
int		is_operator(char *input, int index);

// signal.c
void	signals_process_np(int signum);
void	signals_process_nothing(int signum);
int		signals_handler(void);

// builtin/builtin1.c
int		builtin_echo(char **argv);
int		builtin_cd(char **argv, char **env);
int		builtin_pwd(char **env);
int		builtin_export(char **argv, char **env);

// builtin/builtin2.c
int		builtin_unset(char **argv, char **env);
int		builtin_env(char **env);
int		builtin_exit(char **argv);

// builtin/builtin_util.c
int		is_builtin(char *cmd);
int		execute_builtin(char** argv, char **env);

// env.c
char	**get_env_elements(char **envp, char *key);
char	*get_env_str(char **env, char *key);

// find_pgr_path.c
char	*find_pgr(char *pgr_name, char **envp);

// free.c
void	free_array(char **array);
void	free_token(t_token *head);
void	free_args(char	**args);

// error.c
void	exit_wi_perr(char *message, char **array, char *str);
void	exit_wo_perr(char *message, char *file_or_cmd, \
			char **array, char *str);

#endif
