/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:44:09 by nmandakh          #+#    #+#             */
/*   Updated: 2024/05/11 22:50:19 by root             ###   ########.fr       */
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

# define PIPE_READ_FROM 0
# define PIPE_WRITE_IN 1

# define _POSIX_SOURCE 1

# include <stdbool.h>			// boolean
# include <stdio.h>				// printf
# include <readline/readline.h>	// readline
// rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history
# include <readline/history.h>
# include <stdlib.h>			// malloc, free, exit
// access, fork, execve, getcwd, chdir, close, read,
// write, pipe, dup, dup2, wait, waitpid
# include <unistd.h>
# include <fcntl.h>				// open
// signal, sigaction, sigemptyset, sigaddset, kill
# include <signal.h>
// wait, waitpid, fork, access, open, stat, lstat, fstat,
// dup, dup2, pipe, opendir, readdir, closedir
# include <sys/types.h>
# include <sys/wait.h>			// wait, waitpid, wait3, wait4
# include <sys/stat.h>			// stat, lstat, fstat, unlink
# include <dirent.h>			// opendir, readdir, closedir
# include <string.h>			// strerror
# include <errno.h>				// perror
# include <termios.h>			// tcsetattr, tcgetattr
# include <unistd.h>			// isatty, ttyname, ttyslot, ioctl
// tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <curses.h>
# include <stdlib.h>			// getenv
# include <limits.h>
# include "libft.h"
# include <stdbool.h>

/*
type:
	0 = words (NULL)
	1 = pipe
	2 = redirection
redirect_type:
	0 = NULL
	1 = pipe
	2 = redirect input
	3 = redirect output
	4 = redirect input heredoc
	5 = redirect output append
*/
# define WORDS 0
# define PIPE 1
# define REDIRECTION 2

# define REDIRECT_IN 2
# define REDIRECT_OUT 3
# define REDIRECT_HEREDOC 4
# define REDIRECT_APPEND 5

typedef struct s_token {
	char			*value;
	int				type;
	int				redirect_type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

//need io struct?

typedef struct s_values {
	struct s_token	*head_token;
	int				total_tokens;
	int				total_commands;
	char			**env;
	int				syntax_error;
	int				last_error_code;
}	t_values;

/**************** prototypes ****************/
// main.c
int			main(int argc, char **argv, char **env);

// execute.c
int			execute_commands(t_token *tokens, int index_command, \
			int **pipe_fds_array, char **env);
int			fork_process(t_token *tokens, int **pipe_fds_array, t_values *vals);
int			execute_wrapper(t_token *tokens, t_values *vals);

// redirect.c
int			set_pipe_io(int command_count, int **pipe_fds_array, \
				int total_commands);

// signal.c
void		signals_process_np(int signum);
void		signals_process_nothing(int signum);
int			signals_handler(void);

// initialize.c
t_values	*init_values(char **env);
void		reset_vals_elements(t_values *vals);

// util_execute.c
int			count_all_tokens(t_token *tokens);
int			count_token_argc(t_token *tokens, int num_command);
int			count_commands(t_token *tokens);
char		**tokens_to_argv(t_token *tokens, int num_command);
int			is_last_command(t_token *tokens, int num_command);
int			count_args(char **args);

/**************** lex_analysis ****************/
// lex_analysis/lex_analysis.c
char		*get_next_value(char **input);
int			lexical_analysis(t_token **tokens, char *input, t_values *val);

// lex_analysis/convert.c
t_token		*token_init(void);
void		add_token_types(t_token *token);
void		remove_quote(char *value);
int			process_env_vars(t_token *token);
void		convert_to_token(t_token **tokens, char *value);

// lex_analysis/utils_token.c
int			check_operator(char *input);
int			is_operator(char *input);
int			count_operator_letters(char *input);
int			count_value_size(char *input);

/**************** builtin ****************/
// builtin/
int			builtin_echo(char **argv, bool new_line);
int			builtin_cd(char **argv, char ***env);
int			builtin_pwd(void);
int			builtin_export(char **argv, char **env);
int			builtin_unset(char **argv, char **env);
int			builtin_env(char **env);
int			builtin_exit(char **argv);

// builtin/builtin_util.c
int			is_builtin(char *cmd);
int			execute_builtin(char **argv, char **env);

/**************** utils ****************/
// utils/env.c
void		change_env(char ***env, char *target, char *operation);
char		**get_env_elements(char **envp, char *key);
char		*get_env_value(char *key);
char		*get_env_str(char **env, char *key);
char		*replace_env_var(char *str, int start);

// utils/error.c
void		exit_with_perror(char *message, char **array, char *str);
void		exit_without_perror(char *message, char *file_or_cmd, \
				char **array, char *str);

// utils/find_pgr_path.c
char		*find_pgr(char *pgr_name, char **envp);

// utils/free.c
void		free_array(char **array);
void		free_token(t_token *head);
void		free_args(char	**args);
void		free_vals(t_values *vals);

// utils/ft_myutils.c
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isspace(char c);

// utils/int_array.c
int			**calloc_int_array(int row, int column);
void		free_int_array(int **array, int row);

// utils/node.c
t_token		*last_node(t_token *node);
void		add_to_back(t_token **tokens, t_token *new);

#endif
