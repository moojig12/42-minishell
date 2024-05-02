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

// return next value from input
char	*get_next_value(char **input) // ex.first_pass
{
	char	*ptr;
	int		count;
	int		value_size;

	value_size = count_value_size(*input);
	if (value_size == 0)
		return (NULL); // empty string
	else if (value_size == -1)
		return (NULL); // quote syntax error
	ptr = (char *) malloc((value_size + 1) * sizeof(char));
	if (!ptr)
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
int	lexical_analysis(t_token **tokens, char *input, t_values *val)
{
	char	*value;

	val->head_token = *tokens;
	while (*input)
	{
		if (!ft_isspace(*input))
		{
			value = get_next_value(&input);
			convert_to_token(tokens, value);
		}
		while (ft_isspace(*input))
			input++;
	}
	// if (check_grammer(tokens) == FAILURE);
		// return (FAILURE);
	return (SUCCESS);
}
