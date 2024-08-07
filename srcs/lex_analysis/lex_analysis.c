/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_analysis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:17:51 by root              #+#    #+#             */
/*   Updated: 2024/07/08 14:01:12 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// return next value from input
char	*get_next_value(char **input, t_values *vals)
{
	char	*ptr;
	int		count;
	int		value_size;

	value_size = count_value_size(*input);
	if (value_size == 0)
		return (NULL);
	else if (value_size == -1)
	{
		error_unclosed_quote("quote is not closed", vals);
		return (NULL);
	}
	ptr = (char *)malloc((value_size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	count = 0;
	while (count < value_size)
	{
		ptr[count] = (**input);
		count ++;
		(*input)++;
	}
	ptr[count] = '\0';
	return (ptr);
}

// convert input to tokens
int	lexical_analysis(char *input, t_values *vals)
{
	t_token	**tokens;
	char	*temp;
	char	*token_value;

	tokens = &vals->head_token;
	temp = input;
	while (*temp)
	{
		if (!ft_isspace(*temp))
		{
			token_value = get_next_value(&temp, vals);
			if (token_value == NULL)
				return (EXIT_FAILURE);
			convert_to_token(tokens, token_value, vals);
		}
		while (ft_isspace(*temp))
			temp++;
	}
	if (check_grammar(*tokens, vals) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
