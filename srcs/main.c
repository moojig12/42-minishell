#include "minishell_r.h"

void	interactive_mode(t_values *vals)
{
	prepare_signals();
	while (1)
	{
		vals->input = readline("minishell$ ");
		// prepare_signals_child();
		if (vals->input == NULL)
			break ;
		if (vals->input && vals->input[0])
			add_history(vals->input);
		if (parse_input(vals) == EXIT_SUCCESS)
			vals->exit_code = execution(vals);
		else
			vals->exit_code = EXIT_FAILURE;
	}
}

void	background_mode(t_values *vals, char *argv)
{
	char	**input;
	int		i;

	input = ft_split(argv, ';');
	if (!input)
		exit_shell(vals, EXIT_FAILURE);
	i = 0;
	while (input[i])
	{
		vals->input = ft_strdup(input[i]);
		if (parse_input(vals) == EXIT_SUCCESS)
			vals->exit_code = execution(vals);
		else
			vals->exit_code = EXIT_FAILURE;
		i++;
	}
	free_input_array(input);
}

int	main(int argc, char **argv, char **env)
{
	t_values	*vals;

	vals = init_vals(env);
	if (!vals)
		return (EXIT_FAILURE);
	check_minishell_args(vals, argv, argc);
	if (vals->background)
		background_mode(vals, argv[2]);
	else
		interactive_mode(vals);
	exit_program(vals, vals->exit_code);
	return (0);
}