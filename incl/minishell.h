/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:44:09 by nmandakh          #+#    #+#             */
/*   Updated: 2024/04/03 19:24:48 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
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
# include "../libs/libft/incl/libft.h"

//	Type -> 0 == Command, 1 == Argument, 2 == Operator
typedef struct s_token {
	char	*value;
	int	type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

int		lexical_analysis(t_token **tokens, char *input);
int		count_letters(char *input);
int		is_whitespace(char c);
void	add_to_back(t_token **tokens, t_token *new);
void	skip_letters(char *input, int *i);
void	skip_space(char *input, int *i);
int		check_operator(char *input, int index, int mode);
int		is_operator(char *input, int index);
void	skip_operator(char *input, int *i);


#endif