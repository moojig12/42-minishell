/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:43:58 by nmandakh          #+#    #+#             */
~/*   Updated: 2024/04/03 20:10:20 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

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
}

int	main(void)
{
	int		token_count;
	char	*input;
	t_token	*tokens;

	tokens = NULL;
	rl_outstream = stderr;
	while (1)
	{
		input = readline("minishell$ ");
		if (input == NULL)
			break ;
		if (*input)
			add_history(input);
		//	pass input into lexer
		if (input)
		{
			token_count = lexical_analysis(&tokens, input);
			print_tokens(tokens);
			free(input);
		}
		//	execute
		//	free tokens
		// free_tokens(tokens);
	}
	free (input);
	// free hist
	// free token
	return (SUCCESS);
}
