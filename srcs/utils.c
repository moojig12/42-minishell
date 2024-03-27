/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:25:17 by marvin            #+#    #+#             */
/*   Updated: 2024/03/27 16:58:11 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*iswhitespace(char c)
{
	if (c == '\t' | c == '\n' | c == ' ')
		return (&c);
	else
		return (NULL);
}

void	add_to_back(t_token **tokens, t_token *new)
{
	t_token	*last;

	last = *tokens;
	if (!tokens | !(*tokens))
		*tokens = new;
	else
	{
		last_node(*last);
		last->next = new;
		new->prev = last;
	}
}

void	skip_letters(char *input, int *i)
{
	while (!iswhitespace(input[(*i)]))
	{
		(*i)++;
	}
}

void	skip_letters(char *input, int *i)
{
	while (iswhitespace(input[(*i)]))
	{
		(*i)++;
	}
}

int	count_letters(char *input)
{
	int	i;

	i = 0;
	while (!iswhitespace((input[i])))
	{
		i++;
	}
	return (i);
}
/* int	count_words(char *input)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	skip_space(input, &i);
	while (input[i])
	{
		while (!iswhitespace(input[i]))
		{
			i++;
		}
		words++;
		skip_space(input, &i);
	}
	return (words);
} */