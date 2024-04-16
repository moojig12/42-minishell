/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:43:58 by nmandakh          #+#    #+#             */
/*   Updated: 2024/04/16 19:50:47 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	main(void) // TODO: add env
{
	// int		token_count;
	char	*input;
	// int		token_count;
	t_token	*tokens;

	rl_outstream = stderr;
	while (1)
	{
		input = readline("minishell$ ");
		if (input == NULL)
			break ;
		if (*input)
			add_history(input);
		tokens = NULL;
		// token_count = 
		lexical_analysis(&tokens, input);
		print_tokens(tokens);
		execute(tokens, env);
		free_token(tokens);
		free(input);
	}
	// free hist
	// free token
	return (SUCCESS);
}
