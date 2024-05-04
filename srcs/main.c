/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:43:58 by nmandakh          #+#    #+#             */
/*   Updated: 2024/05/02 19:24:09 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tokens(t_token *token)
{
	t_token	*temp;
	int		i;

	fprintf(stderr, "--------\n");
	i = 0;
	temp = token;
	while (temp != NULL)
	{
		i++;
		fprintf(stderr, "*Token %i*\n value	: %s\n type	: %i\n r_type	: %i\n", \
			i, temp->value, temp->type, temp->redirect_type);
		temp = temp->next;
	}
	fprintf(stderr, "--------\n");
}

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

void	main_process(char *input, t_values *vals)
{
	lexical_analysis(&vals->head_token, input, vals);
	print_tokens(vals->head_token); // TODO: delete later
	if (vals->syntax_error == 1)
	{
		free_token(vals->head_token);
		printf("error: syntax error\n");
		return ;
	}
	execute_wrapper(vals->head_token, vals);
	if (vals->last_error_code != 0)
		printf("error: %s\n", strerror(vals->last_error_code));
	reset_vals_elements(vals);
	free(input);
}

int	main(int argc, char **argv, char **env)
{
	char		*input;
	t_values	*vals;

	if (check_minishell_args(argc, argv) == FAILURE)
		return (FAILURE);
	preparation_process();
	vals = init_values(env);
	if (vals == NULL)
		return (FAILURE);
	while (rl_event_hook != NULL)
	{
		input = readline("minishell$ ");
		if (!input)
			break ;
		if (*input && input[0] != '\t')
			add_history(input);
		main_process(input, vals);
	}
	free(vals);
	write_history(".minishell_history");
	printf("exit\n");
	return (SUCCESS);
}
