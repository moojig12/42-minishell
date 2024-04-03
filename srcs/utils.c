/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:25:17 by marvin            #+#    #+#             */
/*   Updated: 2024/04/03 20:00:33 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	is_whitespace(char c)
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
	while (!is_whitespace(input[*i]) && !is_operator(input, *i) && input[*i])
	{
		(*i)++;
	}
}

void	skip_operator(char *input, int *i)
{
	int	j;

	j = 0;
	while (is_operator(input, *i) && input[*i])
	{
		(*i)++;
	}
}

void	skip_space(char *input, int *i)
{
	while (is_whitespace(input[(*i)]) && input[(*i)])
	{
		(*i)++;
	}
}

int	count_letters(char *input)
{
	int	i;

	i = 0;
	while (!is_whitespace((input[i])) && is_operator(input, i) == 0 && input[i])
	{
		i++;
	}
	return (i);
}


int		check_operator(char *input, int index, int mode)
{
	if (mode == 1)
	{
		if (ft_strncmp(&input[index], "<<", 2) == 0)
			return (2);
		if (ft_strncmp(&input[index], ">>", 2) == 0)
			return (2);
	}
	if (ft_strncmp(&input[index], ">", 1) == 0)
		return (1);
	if (ft_strncmp(&input[index], "<", 1) == 0)
		return (1);
	if (ft_strncmp(&input[index], "|", 1) == 0)
		return (1);
	return (0);
}

int		is_operator(char *input, int index)
{
	int	max;

	max = ft_strlen(input);
	if (index + 1 < max)
		return (check_operator(input, index, 1));
	else
		return (check_operator(input, index, 0));
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
		while (!is_whitespace(input[i]))
		{
			i++;
		}
		words++;
		skip_space(input, &i);
	}
	return (words);
} */