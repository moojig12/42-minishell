/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:44:09 by nmandakh          #+#    #+#             */
/*   Updated: 2024/03/29 12:23:14 by yjinnouc         ###   ########.fr       */
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

# include <unistd.h>
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
