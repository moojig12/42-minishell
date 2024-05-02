/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:43:58 by nmandakh          #+#    #+#             */
/*   Updated: 2024/04/17 06:23:38 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_minishell_args(int argc, char **argv)
{
	if (argc != 1 || argv[1] != NULL)
	{
		printf("Error: minishell does not take any arguments\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

void	preparation_process(void)
{
	using_history();
	read_history(".minishell_history");
	rl_outstream = stderr;
	rl_event_hook = signals_handler;
}

int	main(int argc, char **argv, char **env)
{
	char		*input;
	t_values	*vals;

	if (check_minishell_args(argc, argv) == FAILURE)
		return (FAILURE);
	preparation_process();
	while (rl_event_hook != NULL)
	{
		input = readline("minishell$ ");
		if (!input)
			break ;
		if (*input && input[0] != '\t')
			add_history(input);
		vals = NULL;
		vals = init_values(vals, env);
		if (vals == NULL)
			return (FAILURE);
		lexical_analysis(&vals->head_token, input, vals);
		print_tokens(vals->head_token); // TODO: delete later
		execute_wrapper(vals->head_token, vals);
		free_vals(vals);
		free(input);
	}
	write_history(".minishell_history");
	printf("exit\n");
	return (SUCCESS);
}
