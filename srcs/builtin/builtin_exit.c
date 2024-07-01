/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:05:27 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/06/30 23:29:05 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
exit with no options

exit: exit [n]
	Exit the shell.

	Exits the shell with a status of N.  If N is omitted, the exit status
	is that of the last command executed.
*/


//TODO: need to fix how to handle exit code?? ->check

int ft_isnumber(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	builtin_exit(char **argv)
{
	int exit_code;

	if (argv[1] == NULL)
		exit_code = EXIT_FAILURE;
	else if (ft_isnumber(argv[1]) == FALSE)
	{
		error_command("exit", argv[1], "numeric argument required");
		exit_code = 255;
	}
	// else if (argv[2] != NULL)
	// {
	// 	error_command("exit", NULL, "too many arguments");
	// 	exit_code = 1;
	// }
	else
		exit_code = ft_atoi(argv[1]);
	rl_event_hook = NULL;
	ft_putendl_fd("exit", STDERR_FILENO);
	return (exit_code);
}
