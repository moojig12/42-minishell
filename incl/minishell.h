/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:44:09 by nmandakh          #+#    #+#             */
/*   Updated: 2024/03/27 16:55:17 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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

//	Type -> 0 == Command, 1 == Argument, 2 == Operator
typedef struct s_token {
	char	*value;
	int	type;
	t_token	*next;
	t_token	*prev;
}	t_token;

void	add_to_back(t_token **tokens, t_token *new);
void	*iswhitespace(char c);
void	skip_letters(char *input, int *i);
void	skip_space(char *input, int *i);

#endif