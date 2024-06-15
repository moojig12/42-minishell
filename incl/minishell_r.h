#ifndef MINISHELL_R_H
# define MINISHELL_R_H


# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <limits.h>
# include <termios.h>
# include <errno.h>
# include <dirent.h>
# include "libft.h"

typedef struct termios	t_term;

typedef struct s_redirect
{
	int					redirect;
	int					fd_in;
	int					fd_out;
	char				*file_name;
	char				*heredoc_delim;
	struct s_redirect	*next;
	struct s_redirect	*prev;
}	t_redirect;

typedef struct s_cmd
{
	char			*command;
	char			**args;
	int				argc;
	t_redirect		*redirections;
	int				*pipe_fd;
	int				pipe_in;
	int				pipe_out;
	bool			is_piped;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct s_values {
	char	*input;
	char	**env;
	int		exit_code;
	bool	background;
	t_term	term;
	t_cmd	*cmd;
	pid_t	pid;
}	t_values;

#endif
