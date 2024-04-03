/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:13:58 by marvin            #+#    #+#             */
/*   Updated: 2024/04/03 18:26:19 by nmandakh         ###   ########.fr       */
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

// int		???
//	Add is_operator function

void	convert_to_token(t_token **tokens, char *input, int word)
{
	int	i;
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return ;
	init(new_token, NULL);
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
		convert_to_token(tokens, &input[i], word);
		skip_letters(input, &i);
		if (is_operator(input, i))
			operator_to_token(tokens, input, i, word);
		if (input[i])
			skip_space(input, &i);
		word++;
	}
	return (word);
}
