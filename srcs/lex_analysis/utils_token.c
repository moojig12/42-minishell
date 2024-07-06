/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:16:13 by root              #+#    #+#             */
/*   Updated: 2024/05/12 23:24:29 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// input length should be more than 1 (1 + '\0')
int	check_operator(char *input)
{
	if (ft_strncmp(input, ">>", 2) == 0)
		return (5);
	if (ft_strncmp(input, "<<", 2) == 0)
		return (4);
	if (ft_strncmp(input, ">", 1) == 0)
		return (3);
	if (ft_strncmp(input, "<", 1) == 0)
		return (2);
	if (ft_strncmp(input, "|", 1) == 0)
		return (1);
	return (0);
}

int	is_operator(char *input)
{
	if (check_operator(input) > 0)
		return (TRUE);
	else
		return (FALSE);
}

int	count_operator_letters(char *input)
{
	if (check_operator(input) >= 4)
		return (2);
	else if (check_operator(input) > 0)
		return (1);
	else
		return (0);
}

// count the size of the value incl quotes
//   or return error(FAILURE = -1) if quote is not closed
int	count_value_size(char *input)
{
	bool	single_quoted;
	bool	double_quoted;
	int		count;

	single_quoted = FALSE;
	double_quoted = FALSE;
	count = 0;
	while (input[count])
	{
		if (!single_quoted && !double_quoted && ft_isspace(input[count]))
			return (count);
		if (!single_quoted && !double_quoted && check_operator(&input[count]))
		{
			count += count_operator_letters(&input[count]);
			return (count);
		}
		if (input[count] == '\'' && !double_quoted)
			single_quoted = !single_quoted;
		if (input[count] == '"' && !single_quoted)
			double_quoted = !double_quoted;
		count++;
	}
	if (single_quoted || double_quoted)
		return (-1);
	return (count);
}
