/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:13:58 by marvin            #+#    #+#             */
/*   Updated: 2024/04/23 17:42:23 by root             ###   ########.fr       */
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
	while (*input && !ft_isspace(*input) && !is_operator(input, 0) && !is_quote(*input))
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
	int		k;
	int		len;
	// look for closing quote while counting bytes
	j = 1;
	(*i)++;
	len = ft_strlen(input);
	found = FALSE;
	while (input[j])
	{
		if (input[j] == '"')
		{
			(*i)++;
			j++;
			found = TRUE;
			printf("found? %i, %c\n", j, input[j]);
			if (input[j] && (ft_isspace(input[j]) || is_operator(input, j)))
			{
				len = j - 1;
				break ;
			}
			printf("didn't break\n");
		}
		else
		{
			(*i)++;
			j++;
			if (found && (ft_isspace(input[j]) || is_operator(input, j)))
			{
				len = j;
				break ;
			}
		}
	}
	// "test"
	if (!found)
		exit_with_perror("Unclosed quote!\n", NULL, NULL);
	// malloc and assign to token->value
	result = (char *)malloc((len + 1) * sizeof(char));
	j = 0;
	k = 1;
	printf("size: %i\n", len);
	while (j < len)
	{
		if (input[k] != '"')
		{
			result[j] = input[k];
			j++;
			k++;
		}
		else
			k++;
	}
	result[j] = 0;
	printf("%s\n", result);
	// skip until end of quote string?
	return (result);
}

void	string_to_token(t_token **tokens, char *string, int word)
{
	t_token	*new_token;

	new_token = init("argument");
	if (word == 1)
		new_token->type = 0;
	new_token->value = string;
	add_to_back(tokens, new_token);
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
				string_to_token(tokens, quotes_to_string(&input[i], &i), word);
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
