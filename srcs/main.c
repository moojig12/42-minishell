/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:43:58 by nmandakh          #+#    #+#             */
/*   Updated: 2024/03/22 19:27:47 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	main(void)
{
	int		token_count;
	char	*input;
	t_token	*tokens;

	while (1)
	{
		input = readline("minishell:");
		//	pass input into lexer
		token_count = lexical_analysis(tokens, input);
		//	Process commands
		
		//	fork and execute
		//	wait();
		
		//	add history to readline
		
		//	free;
	}
}