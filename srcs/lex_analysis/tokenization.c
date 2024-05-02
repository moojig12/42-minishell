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

t_token	*token_init(void)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	// if (!ft_strncmp(mode, "operator", ft_strlen(mode)))
	// 	new->type = 2;
	// else if (!ft_strncmp(mode, "argument", ft_strlen(mode)))
	// 	new->type = 1;
	// else
	new->type = 0;
	new->value = 0;
	new->redirect_type = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_token_types(t_token *token)
{
	int	len_value;
	int	type_value;

	len_value = (int) ft_strlen(token->value);
	type_value = check_operator(token->value);
	if (len_value == 1 && type_value == 1)
		token->type = 2;
	else if (len_value == 1 && (type_value == 2 || type_value == 3))
	{
		token->type = 1;
		token->redirect_type = type_value;
	}
	else if (len_value == 2 && (type_value == 4 || type_value == 5))
	{
		token->type = 1;
		token->redirect_type = type_value;
	}
}

// remove unneeded quotes from value
void	remove_quote(char *value)
{
	char	*copy;
	char	*ptr_copy;
	bool	single_quoted;
	bool	double_quoted;

	single_quoted = FALSE;
	double_quoted = FALSE;
	copy = ft_strdup(value);
	ptr_copy = copy;
	while (*ptr_copy)
	{
		if (*ptr_copy == '\'' && !double_quoted)
			single_quoted = !single_quoted;
		else if (*ptr_copy == '"' && !single_quoted)
			double_quoted = !double_quoted;
		else if ((*ptr_copy != '\'' && *ptr_copy != '"') || \
			single_quoted || !double_quoted)
			*value++ = *ptr_copy;
		ptr_copy++;
	}
	*value = '\0';
	free(copy);
}

// add input as a token to the end of the list
void	convert_to_token(t_token **tokens, char *input)
{
	t_token	*new_token;

	new_token = token_init();
	new_token->value = input;
	// if (word == 1)
	// 	new_token->type = 0;
	add_token_types(new_token);
	// replace environment variables()
	remove_quote(input);
	new_token->value = input;
	add_to_back(tokens, new_token);
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
		printf("*Token %i*\n value: %s\n type: %i\n", i, temp->value, temp->type);
		temp = temp->next;
	}
	printf("----\n\n");
}
