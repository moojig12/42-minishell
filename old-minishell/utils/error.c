/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:31:50 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/13 01:22:58 by yjinnouc         ###   ########.fr       */
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
		vals->last_error_code = errno;
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
	vals->last_error_code = 127;
	exit (127);
}

void	set_error_waitpid(int status, t_values *vals)
{
	strerror(status);
	if (WIFEXITED(status))
		vals->last_error_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		vals->last_error_code = WTERMSIG(status);
	else if (WIFSTOPPED(status))
		vals->last_error_code = WSTOPSIG(status);
	else
		vals->last_error_code = 0;
	return ;
}

void	error_unclosed_quote(char *message, t_values *vals)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	vals->last_error_code = 1;
	vals->syntax_error = TRUE;
	return ;
}

void	error_grammar(char *message, t_values *vals)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("syntax error near unexpected token `", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("'\n", 2);
	vals->last_error_code = 1;
	vals->syntax_error = TRUE;
	return ;
}

void	error_io(char *message, t_values *vals)
{
	ft_putstr_fd("minishell: ", 2);
	perror(message);
	vals->last_error_code = 1;
	return ;
}
