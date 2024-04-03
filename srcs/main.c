/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:43:58 by nmandakh          #+#    #+#             */
/*   Updated: 2024/04/03 21:16:02 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	main(int argc, char** argv) //, char **env)
{
	int		token_count;
	char	*input;
	t_token	*tokens;

	tokens = NULL;
	if (argc != 1 || argv[1] != NULL)
	{
		printf("Error: minishell does not take any arguments\n");
		return (FAILURE);
	}
	rl_outstream = stderr;
	rl_event_hook = signals_handler;
	while (rl_event_hook != NULL)
	{
		input = readline("minishell$ ");
		if (input == NULL) // FIX: add when input == EOF
			break ;
		if (*input)
			add_history(input);
		//	pass input into lexer
		token_count = lexical_analysis(&tokens, input);
		print_tokens(tokens);
		//	execute
		//	free tokens
		// free_tokens(tokens);
		free(input);
	}
	//free token
	printf("exit\n");
	return (SUCCESS);
}
