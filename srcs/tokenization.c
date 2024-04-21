/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:13:58 by marvin            #+#    #+#             */
/*   Updated: 2024/04/21 13:16:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*init(char *mode)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	if (!ft_strncmp(mode, "operator", ft_strlen(mode)))
		new->type = 2;
	else if (!ft_strncmp(mode, "argument", ft_strlen(mode)))
		new->type = 1;
	else
		new->type = INT_MIN;
	new->value = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	convert_to_token(t_token **tokens, char *input, int word)
{
	t_token	*new_token;
	int		i;

	new_token = init("argument");
	if (word == 1)
		new_token->type = 0;
	i = 0;
	new_token->value = \
		(char *)malloc((count_letters(input) + 1) * sizeof(char));
	while (!is_whitespace(*input) && !is_operator(input, 0) && *input)
	{
		new_token->value[i] = *input;
		input++;
		i++;
	}
	new_token->value[i] = '\0';
	add_to_back(tokens, new_token);
}

void	operator_to_token(t_token **tokens, char *input, int index)
{
	t_token	*new_token;
	int		i;

	i = 0;
	new_token = init("operator");
	new_token->value = \
		(char *)malloc((is_operator(input, index) + 1) * sizeof(char));
	while (is_operator(input, index))
	{
		new_token->value[i] = input[index];
		index++;
		i++;
	}
	new_token->value[i] = '\0';
	add_to_back(tokens, new_token);
}

char	*quotes_to_string(char *input, int *i)
{
	char	*result;
	bool	found;
	int		j;
	int		len;
	// look for closing quote while counting bytes
	j = 1;
	len = ft_strlen(input);
	while (input[j])
	{
		if (input[j] == '"')
		{
			found = TRUE;
			break ;
		}
		else
		{
			(*i)++;
			j++;
		}
	}
	// "test"
	if (len == j)
		exit_wi_perr("Unclosed quote!\n", NULL, NULL);
	// malloc and assign to token->value
	result = (char *)malloc((j - 1) * sizeof(char));
	j = 1;
	while (j < len - 2)
	{
		result[j - 1] = input[j];
	}
	// skip until end of quote string?
}

int	lexical_analysis(t_token **tokens, char *input)
{
	int	word;
	int	i;

	word = 1;
	i = 0;
	skip_space(input, &i);
	while (input[i])
	{
		printf("pre_in: %s\n\n", &input[i]);
		if (!is_operator(input, i))
		{
			if (is_quote(input[i]))
			{
				convert_to_token(tokens, quotes_to_string(&input[i], &i), word);
			}
			else
			{
				convert_to_token(tokens, &input[i], word);
				skip_letters(input, &i);
			}
			word++;
		}
		if (is_operator(input, i))
		{
			operator_to_token(tokens, input, i);
			skip_operator(input, &i);
			word = 1;
		}
		if (input[i])
			skip_space(input, &i);
		// print_tokens(*tokens);
	}
	ft_printf("--------\n");
	return (SUCCESS);
}

void	print_tokens(t_token *token)
{
	t_token	*temp;
	int		i;

	i = 0;
	temp = token;
	while (temp != NULL)
	{
		i++;
		printf("*Token %i*\nvalue: %s\ntype: %i\n", i, temp->value, temp->type);
		temp = temp->next;
	}
	printf("----\n");
}
