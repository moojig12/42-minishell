/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:17:51 by root              #+#    #+#             */
/*   Updated: 2024/04/27 01:19:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Checks whether the function is still reading within an enclosed quote
static bool	switch_off(char *input, int *i, bool i_q)
{
	if (input[*i] && is_quote(input[*i]))
	{
		(*i)++;
		return (FALSE);
	}
	return (TRUE);
}

static void	count_quoted(char *input, int *i, int *count, bool *i_q)
{
	(*count)++;
	(*i)++;
	*i_q = switch_off(input, i);

}

static void	count_unquoted(char *input, int *i, int *count)
{
	(*count)++;
	(*i)++;
	if (input[i] && ft_isspace(input[i]))
		break ;
}

static void check_if_quote(char *input, int *i, bool *i_q)
{
	if (is_quote(input[*i]))
	{
		*i_q = TRUE;
		(*i)++;
	}
}

int	count_size(char *input, int i)
{
	bool	inside_quote;
	int		count;

	inside_quote = FALSE;
	count = 0;
	while (input[i])
	{
		check_if_quote();
		if (inside_quote)
			count_quoted(input, &i, &count, &inside_quote);
		else
			count_unquoted(input, &i, &count, &inside_quote);
	}
}

char	*first_pass(t_token **tokens, char *input, int word, int *i)
{
	char	*res;
	char	*temp;
	char	*q_str;

	res = (char *)malloc(count_size(&input[*i], &i) * sizeof(char));
	if (!res)
		return (NULL);
	while (input[*i])
	{
		if (!is_quote(input[*i]))
		{
			
		}
		/* if (is_quote(input[*i]))
		{
			q_str = quote_to_str(input, i);
			temp = ft_strjoin(res, q_str);
			free(res);
			res = ft_strdup(temp);
		}
		else
		{
			// convert to str normally
			
			(i*)++;
		} */
	}
	return (res);
}

void	lexical_analysis(t_token **tokens, char *input)
{
	int		i;
	int		word;

	i = 0;
	word = 1;
	while (input[i])
	{
		if (!ft_isspace(input[i]))
		{
			convert_to_token(tokens, first_pass(tokens, input, word, &i), word);
			word++;
		}
		else
			skip_space(input, &i);
		i++;
	}
}

