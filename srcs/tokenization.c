/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:13:58 by marvin            #+#    #+#             */
/*   Updated: 2024/04/21 14:00:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	init(t_token *new, char mode)
{
	if (ft_strncmp(mode, "operator", ft_strlen(mode)))
		new->type = 2;
	else
		new->type = INT_MIN;
	new->value = NULL;
	new->next = NULL;
	new->prev = NULL;
}

int		check_operator(char *input, int index, int mode)
{
	int	res;

	res = 0;
	if (mode == 1)
	{
		res = ft_strncmp(&input[index], "<<", 2);
		res = ft_strncmp(&input[index], ">>", 2);
	}
	res = ft_strncmp(&input[index], ">", 1);
	res = ft_strncmp(&input[index], "<", 1);
	res = ft_strncmp(&input[index], "|", 1);
	return (res);
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

int		
//	Add is_operator function

void	convert_to_token(t_token **tokens, char *input, int word)
{
	int	i;
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return ;
	init(new_token);
	if (word == 1)
		new_token->type = 1;
	i = 0;
	new_token->value = (char *)malloc((count_letters(input) + 1) * sizeof(char));
	while (!is_whitespace(*input) && *input)
	{
		new_token->value[i] = *input;
		input++;
		i++;
	}
	new_token->value[i] = '\0';
	add_to_back(tokens, new_token);
}

void	operator_to_token(t_token **tokens, char *input, int index, int word)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return ;
	init(new_token, "operator");
}

char	*quotes_to_string(char *input, int *i)
{
	char	*result;
	bool	found;
	int		j;
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
			if (input[j] && (is_whitespace(input[j]) || is_operator(input, j)))
				break ;
			printf("didn't break\n");
		}
		else
		{
			(*i)++;
			j++;
		}
	}
	// "test"
	if (!found)
		exit_wi_perr("Unclosed quote!\n", NULL, NULL);
	// malloc and assign to token->value
	result = (char *)malloc((j - 1) * sizeof(char));
	len = j - 1;
	j = 1;
	while (j < len)
	{
		result[j - 1] = input[j];
		j++;
	}
	result[j - 1] = 0;
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

	/* word = count_words(input);
	if (word == 0)
		error("No arguments found"); */
	i = 0;
	word = 1;
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
			operator_to_token();
		if (input[i])
			skip_space(input, &i);
		word++;
	}
	return (word);
}
