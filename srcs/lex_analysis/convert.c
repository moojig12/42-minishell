/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:13:58 by marvin            #+#    #+#             */
/*   Updated: 2024/07/10 15:27:20 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
- Handle quote which should prevent the shell
	from interpreting the meta-characters,
- ’ (single quote): in the all quoted sequence
- " (double quote): in the quoted sequence except for $ (dollar sign).
*/

t_token	*token_init(void)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->type = 0;
	new->value = 0;
	new->redirect_type = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
	// new->command_index = 0;??

void	add_token_types(t_token *token)
{
	int	len_value;
	int	type_value;

	len_value = (int) ft_strlen(token->value);
	type_value = check_operator(token->value);
	if (len_value == 1 && type_value == PIPE)
		token->type = PIPE;
	else if (len_value == 1 && \
		(type_value == REDIRECT_IN || type_value == REDIRECT_OUT))
	{
		token->type = REDIRECTION;
		token->redirect_type = type_value;
	}
	else if (len_value == 2 && \
		(type_value == REDIRECT_HEREDOC || type_value == REDIRECT_APPEND))
	{
		token->type = REDIRECTION;
		token->redirect_type = type_value;
	}
}

int	process_env_vars(t_token *token, t_values *vals)
{
	bool	single_quoted;
	bool	double_quoted;
	int		i;

	single_quoted = FALSE;
	double_quoted = FALSE;
	i = 0;
	while (token->value[i] != '\0')
	{
		if (token->value[i] == '\'' && !double_quoted)
			single_quoted = !single_quoted;
		if (token->value[i] == '"' && !single_quoted)
			double_quoted = !double_quoted;
		if (token->value[i] == '$' && !single_quoted && \
			token->value[i + 1] != '\0')
			{
				token->value = replace_wrapper(token->value, i, vals);
				i --;
			}
		i++;
	}
	return (EXIT_SUCCESS);
}

// remove unneeded quotes from value
void	remove_quote(char *value)
{
	char	*copy;
	char	*ptr_copy;
	bool	single_quoted;
	bool	double_quoted;

	single_quoted = false;
	double_quoted = false;
	copy = ft_strdup(value);
	ptr_copy = copy;
	while (*ptr_copy)
	{
		if (*ptr_copy == '\'' && !double_quoted)
			single_quoted = !single_quoted;
		else if (*ptr_copy == '"' && !single_quoted)
			double_quoted = !double_quoted;
		else
			*value++ = *ptr_copy;
		ptr_copy++;
	}
	*value = '\0';
	free(copy);
}

// add input as a token to the end of the list
void	convert_to_token(t_token **tokens, char *value, t_values *vals)
{
	t_token	*new_token;

	new_token = token_init();
	new_token->value = value;
	add_token_types(new_token);
	process_env_vars(new_token, vals);
	remove_quote(new_token->value);
	add_to_back(tokens, new_token);
}
