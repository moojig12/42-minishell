/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:43:58 by nmandakh          #+#    #+#             */
/*   Updated: 2024/04/16 19:42:32 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*input;
	int		token_count;
	t_token	*tokens;

	if (argc != 1 || argv[1] != NULL)
	{
		printf("Error: minishell does not take any arguments\n");
		return (FAILURE);
	}
	using_history();
	read_history(".minishell_history");
	rl_outstream = stderr;
	rl_event_hook = signals_handler;
	while (rl_event_hook != NULL)
	{
		input = readline("minishell$ ");
		if (input == NULL) //FIX: will make error with *input == 0
			break ;
		if (*input)
			add_history(input);
		tokens = NULL;
		token_count = lexical_analysis(&tokens, input);
		printf("Tokens = %i\n", token_count);
		print_tokens(tokens);
		execute(tokens, env);
		free_token(tokens);
		free(input);
	}
	write_history(".minishell_history");
	printf("exit\n");
	return (SUCCESS);
}
