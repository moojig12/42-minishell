/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:57:26 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/06/30 21:42:30 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*exit process with perror*/
/*just copy from jini's pipex*/
void	exit_with_perror(char *message, t_values *vals)
{
	perror("minishell");
	perror(message);
	if (errno)
	{
		fprintf(stderr, "errno: %d\n", errno); // TODO: delete later
		vals->last_exit_code = errno;
		exit (errno);
	}
	exit (EXIT_FAILURE);
}

void	exit_command_not_found(char *cmd, char **argv, t_values *vals)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putchar_fd('\n', 2);
	free_array(argv);
	vals->last_exit_code = 127;
	exit (127);
}

/*
exit cleanly (with free vals) from minishell
exit code is undefined with -1, it means exit with last_exit_code
*/
void exit_shell(int exit_code, t_values *vals)
{
	int status;

	if (exit_code == -1)
		status = vals->last_exit_code;
	else
		status = exit_code;
	free_vals_elements(vals);
	exit(status);
}
