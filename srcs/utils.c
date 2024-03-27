/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:25:17 by marvin            #+#    #+#             */
/*   Updated: 2024/03/27 17:26:00 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	iswhitespace(char c)
{
	if (c == '\t' | c == '\n' | c == ' ')
		return (1);
	else
		return (0);
}

t_token	*last_node(t_token *node)
{
	t_token	*temp;

	if (!node)
		return (NULL);
	temp = node;
	while(temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

void	add_to_back(t_token **tokens, t_token *new)
{
	t_token	*last;

	last = *tokens;
	if (!tokens | !(*tokens))
		*tokens = new;
	else
	{
		last = last_node(last);
		last->next = new;
		new->prev = last;
	}
}

void	skip_letters(char *input, int *i)
{
	while (!iswhitespace(input[(*i)]) && input[(*i)])
	{
		(*i)++;
	}
}

void	skip_space(char *input, int *i)
{
	while (iswhitespace(input[(*i)]) && input[(*i)])
	{
		(*i)++;
	}
}

int	count_letters(char *input)
{
	int	i;

	i = 0;
	while (!iswhitespace((input[i])) && input[i])
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