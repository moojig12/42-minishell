/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:43:58 by nmandakh          #+#    #+#             */
/*   Updated: 2024/07/01 08:56:37 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
void	print_tokens(t_token *token) //TODO: delete later
{
	t_token	*temp;
	int		i;

	ft_putendl_fd("--------", STDERR_FILENO);
	i = 0;
	temp = token;
	while (temp != NULL)
	{
		i++;
		fprintf(stderr, "*Token %i*\n value	: %s\n type	: %i\n r_type	: %i\n", \
			i, temp->value, temp->type, temp->redirect_type);
		temp = temp->next;
	}
	ft_putendl_fd("--------", STDERR_FILENO);
}
*/

int	preparation_before_command(int argc, char **argv)
{
	if (argc > 1 && argv[1] != NULL)
	{
		ft_putstr_fd("Error: ", STDERR_FILENO);
		ft_putendl_fd("minishell does not take any arguments", \
			STDERR_FILENO);
		return (FAILURE);
	}
	using_history();
	read_history(".minishell_history");
	rl_outstream = stderr;
	rl_event_hook = signals_handler;
	return (SUCCESS);
}

void	save_input_and_free(char *input)
{
	if (input == NULL)
		return;
	if (input[0] != '\0')
		add_history(input);
	free(input);
}

int	main(int argc, char **argv, char **env)
{
	t_values	*vals;
	char		*input;

	if (preparation_before_command(argc, argv) == FAILURE)
		return (FAILURE);
	if ((vals = init_values(env)) == NULL)
		return (FAILURE);
	while (rl_event_hook != NULL)
	{
		input = readline(PROMPT);
		if (input == NULL)
			input = ft_strdup("exit");
		if (!isatty(STDIN_FILENO) && input[0] == '\0')
			break ;
		if (input[0] != '\0')
			execute_wrapper(input, vals);
		reset_vals_elements(vals);
		save_input_and_free(input);
	}
	write_history(".minishell_history");
	exit_shell(-1, vals);
}
