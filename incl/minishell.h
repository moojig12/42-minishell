/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:44:09 by nmandakh          #+#    #+#             */
/*   Updated: 2024/04/20 12:00:36 by root             ###   ########.fr       */
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

# include <stdbool.h>			// boolean
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
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <termios.h>
# include <errno.h>
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

// histry.c
// t_hist 	*add_history(char *input, t_hist *head);

// main.c
int		main(void); // TODO: add env

//tokenization.c
// int	count_words(char *input);
void	convert_to_token(t_token **tokens, char *input, int word);
int	lexical_analysis(t_token **tokens, char *input);

//free.c
void	free_array(char **array);

//error.c
void	exit_wi_perr(char *message, char **array, char *str);
void	exit_wo_perr(char *message1, char *file_or_cmd, \
			char **array, char *str);

#endif
