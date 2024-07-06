/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_defs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:44:09 by nmandakh          #+#    #+#             */
/*   Updated: 2024/07/01 09:37:04 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_DEFS_H
# define MINISHELL_DEFS_H 1

# define TRUE 1
# define FALSE 0

# define _POSIX_SOURCE 1

# define PROMPT "\e[1;32mminishell$ \e[0m"

/**************** Error Handling ****************/
/* System error */
# define OP_SUCCESS		1
# define IDX_NOT_FOUND	-1
# define MEM_ERROR  	7
# define MANY_ERROR		1
# define NUM_ERROR		2
# define ARG_ERROR  	3
# define CMD_ERROR		4
# define FORK_ERROR		5
# define DUP_ERROR		6

/* Command errors */
# define INVALID_KEY	1
# define INVALID_PARM	1
# define CMD_NOT_FOUND	127
# define CMD_NOT_EXEC	126

/* Redirection errors */
# define FILE_NF		20
# define RED_IN_ERR		21
# define RED_OUT_ERR	22
# define INVALID_FNAME	23

/* Redirection errors */
# define FILE_NF		20
# define RED_IN_ERR		21
# define RED_OUT_ERR	22
# define INVALID_FNAME	23

/* Tokenizer errors */
# define EOF_ERROR		24

/* Parsing Tree errors */
# define SYNTAX_ERROR	25

/**************** Redirection / Pipe ****************/
# define TMP_FILENAME "/tmp/heredoc_tmp.tmp"
# define FILE_NF		20
# define RED_IN_ERR		21
# define RED_OUT_ERR	22
# define INVALID_FNAME	23

# define PIPE_READ_FROM 0
# define PIPE_WRITE_IN 1

// difinitions for token types

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

/**************** Structures ****************/
// save tokens for parsing
typedef struct s_token {
	char			*value;
	int				type;
	int				redirect_type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

//save io redirection for reset after command execution
typedef struct s_io {
	int				save_fd;
	int				dest_fd;
	struct s_io		*next;
}	t_ios;

// save all values for minishell
typedef struct s_values {
	struct s_token	*head_token;
	int				total_tokens;
	int				total_commands;
	struct s_io		*head_io;
	char			**env;
	int				syntax_error;
	int				execute_error;
	int				last_exit_code;
}	t_values;

#endif
