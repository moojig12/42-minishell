/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:16:13 by root              #+#    #+#             */
/*   Updated: 2024/07/01 08:54:57 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_acceptable(char c)
{
	if (ft_isascii(c) == FALSE)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putendl_fd("some characters are not ascii", STDERR_FILENO);
		return (FALSE);
	}
	else if (c == '\\' || c == ';' || c == '*')
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd("This shell does not accept some special characters" \
		, STDERR_FILENO);
		ft_putendl_fd("like '\\', ';', '*'", STDERR_FILENO); // TODO: check if this is okay
		return (FALSE);
	}
	else if (ft_isalnum(c) == TRUE)
		return (TRUE);
	return (TRUE);
}

int	check_value(char *value)
{
	int	i;

	i = 0;
	while (value[i])
	{
		if (is_acceptable(value[i]) == FALSE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	is_operator_grammar_error(t_token *temp, t_values *vals)
{
	if (temp->type == PIPE || temp->type == REDIRECTION)
	{
		if (temp->next == NULL)
		{
			error_grammar("newline", vals);
			return (FAILURE);
		}
		if (temp->next->type != WORDS)
		{
			error_grammar(temp->next->value, vals);
			return (FAILURE);
		}
	}
	return (TRUE);
}

int	check_grammar(t_token *tokens, char *input, t_values *vals)
{
	t_token	*temp;

	/* if (check_value(input) == FAILURE)
	{
		vals->syntax_error = TRUE;
		return (FAILURE);
	} */
	if (!input || !tokens)
	{
		return (FAILURE);
	}
	temp = tokens;
	if (temp->type != WORDS)
	{
		if (temp->next == NULL)
			return (FAILURE);
		error_grammar(temp->next->value, vals);
		return (FAILURE);
	}
	while (temp != NULL)
	{
		if (is_operator_grammar_error(temp, vals) == FAILURE)
			return (FAILURE);
		temp = temp->next;
	}
	return (SUCCESS);
}
