/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:43:58 by nmandakh          #+#    #+#             */
/*   Updated: 2024/05/13 17:39:10 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tokens(t_token *token)
{
	t_token	*temp;
	int		i;

	ft_putendl_fd("--------", 2);
	i = 0;
	temp = token;
	while (temp != NULL)
	{
		i++;
		fprintf(stderr, "*Token %i*\n value	: %s\n type	: %i\n r_type	: %i\n", \
			i, temp->value, temp->type, temp->redirect_type);
		temp = temp->next;
	}
	ft_putendl_fd("--------", 2);
}

int	check_minishell_args(int argc, char **argv)
{
	if (argc != 1 || argv[1] != NULL)
	{
		ft_putendl_fd("Error: minishell does not take any arguments", 2);
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

int	main_process(char *input, t_values *vals)
{
	if (lexical_analysis(&vals->head_token, input, vals) == FAILURE)
	{
		vals->syntax_error = TRUE;
		vals->last_error_code = 1;
		return (FAILURE);
	}
	// print_tokens(vals->head_token); // TODO: delete later
	execute_wrapper(vals->head_token, vals);
	if (vals->last_error_code != 0)
	{
		// ft_putstr_fd("error: ", 2);
		// ft_putendl_fd(strerror(vals->last_error_code), 2);
	}
	return (SUCCESS);
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
		if (input[0])
			main_process(input, vals);
		reset_vals_elements(vals);
		free(input);
	}
	free_array(vals->env);
	if (vals)
		free(vals);
	write_history(".minishell_history");
	ft_putendl_fd("exit", 1);
	return (SUCCESS);
}
