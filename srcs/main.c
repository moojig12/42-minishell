/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:43:58 by nmandakh          #+#    #+#             */
/*   Updated: 2024/03/29 12:11:14 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void) // TODO: add env
{
	// int		token_count;
	char	*input;
	// t_token	*tokens;

	rl_outstream = stderr;
	while (1)
	{
		input = readline("minishell$ ");
		if (input == NULL)
			break ;
		if (*input)
			add_history(input);
		//	pass input into lexer
		// token_count = lexical_analysis(&tokens, input);
	}
	free (input);
	// free hist
	// free token
	return (SUCCESS);
}
