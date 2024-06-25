/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:44:09 by nmandakh          #+#    #+#             */
/*   Updated: 2024/06/23 16:31:12 by root             ###   ########.fr       */
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
	// int 			command_index;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

//need io struct?
typedef struct s_io {
	int				fd;
	int				old_fd;
	struct s_io		*next;
}	t_ios;

typedef struct s_values {
	struct s_token	*head_token;
	int				total_tokens;
	int				total_commands;
	struct s_io		*head_io;
	char			**env;
	int				syntax_error;
	int				execute_error;
	int				last_error_code;
}	t_values;

/**************** prototypes ****************/
// main.c
int			main(int argc, char **argv, char **env);

// execute.c
int			execute_commands(t_token *tokens, int index_command, \
			int **pipe_fds_array, t_values *vals);
int			fork_process(t_token *tokens, int **pipe_fds_array, t_values *vals);
int			execute_wrapper(t_token *tokens, t_values *vals);

// signal.c
void		signals_process_np(int signum);
void		signals_process_nothing(int signum);
int			signals_handler_child(void);
int			signals_handler(void);
void		sigquit_process(int signum);

// initialize.c
t_values	*init_values(char **env);
void		reset_vals_elements(t_values *vals);

// util_execute.c
int			count_all_tokens(t_token *tokens);
int			count_token_argc(t_token *tokens, int num_command);
int			count_commands(t_token *tokens);
char		**tokens_to_argv(t_token *tokens, int num_command);
int			is_last_command(t_token *tokens, int num_command);
int			count_str_array(char **args);

/**************** lex_analysis ****************/
// lex_analysis/lex_analysis.c
char		*get_next_value(char **input, t_values *vals);
int			lexical_analysis(t_token **tokens, char *input, t_values *vals);

// lex_analysis/convert.c
t_token		*token_init(void);
void		add_token_types(t_token *token);
void		remove_quote(char *value);
int			process_env_vars(t_token *token, t_values *vals);
void		convert_to_token(t_token **tokens, char *value, t_values *vals);

// lex_analysis/grammar_check.c
int			check_grammar(t_token *tokens, char *input, t_values *vals);

// lex_analysis/utils_token.c
int			check_operator(char *input);
int			is_operator(char *input);
int			count_operator_letters(char *input);
int			count_value_size(char *input);

/**************** redirect ****************/
// redirect/redirect.c
int			set_pipe_io(int command_count, int **pipe_fds_array, \
				int total_commands);
int			set_redirect(t_token *head, int index_command, t_values *vals);
int			reset_redirect(t_values *vals);

// redirect/redirect_*.c
int			redirect_input(t_token *temp, t_values *vals);
int			redirect_output(t_token *temp, t_values *vals);
int			redirect_heredoc(t_token *temp, t_values *vals);
int			redirect_append(t_token *token, t_values *vals);

// redirect/redirect_util.c
t_ios		*init_ios(int fd, int old_fd);
int			save_fd(int fd, int old_fd, t_values *s);

/**************** builtin ****************/
// builtin/*.c
int			builtin_echo(char **argv);
int			builtin_cd(char **argv, t_values *vals);
int			builtin_pwd(void);
int			builtin_export(char **argv, t_values *vals);
int			builtin_unset(char **argv, t_values *vals);
int			builtin_env(t_values *vals);
int			builtin_exit(char **argv);

// builtin/builtin_util.c
int			is_builtin(char *cmd);
int			execute_builtin(char **argv, t_values *vals);

/**************** utils ****************/
// utils/env.c
int			change_env(char *key, char *value, char *operation, t_values *vals);
char		**get_env_elements_array(char **envp, char *key);
char		*get_env_value(char *key);
char		*get_env_str(char **env, char *key);
char		*replace_env_var(char *str, int start, t_values *vals);

// utils/error.c
void		exit_with_perror(char *message, t_values *vals);
void		exit_without_perror(char *message, char *file_or_cmd, \
				char **array, char *str);
void		exit_command_not_found(char *cmd, char **argv, t_values *vals);
void		set_error_waitpid(int status, t_values *vals);
void		error_unclosed_quote(char *message1, t_values *vals);
void		error_grammar(char *message, t_values *vals);
void		error_io(char *message, t_values *vals);

// utils/find_pgr_path.c
char		*find_pgr(char *pgr_name, t_values *vals);

// utils/free.c
void		free_vals_elements(t_values *vals);
void		free_array(char **array);
void		free_token(t_token *head);
void		free_vals(t_values *vals);

// utils/ft_myutils.c
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isspace(char c);
char		*ft_3strjoin(char *str, char *str2, char *str3);
char		*ft_strndup(const char *s, size_t n);
int			ft_ispathkey(char *key);

// utils/int_array.c
int			**calloc_int_array(int row, int column);
void		free_int_array(int **array, int row);

// utils/node.c
t_token		*last_node(t_token *node);
void		add_to_back(t_token **tokens, t_token *new);
t_token		*get_command_head(t_token *head, int index_command);
t_token		*get_next_redirection(t_token *command_head);

/**************** test ****************/
// test/test_fd.c
int			test_fds(void);

#endif
