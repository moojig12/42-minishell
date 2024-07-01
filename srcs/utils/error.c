/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:31:50 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/01 08:58:08 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_error_waitpid(int status, t_values *vals)
{
	vals->execute_error = TRUE;
	// strerror(status);
	if (WIFEXITED(status))
		vals->last_exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		vals->last_exit_code = WTERMSIG(status);
	else if (WIFSTOPPED(status))
		vals->last_exit_code = WSTOPSIG(status);
	return ;
}

void	error_unclosed_quote(char *message, t_values *vals)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	vals->last_exit_code = 1;
	vals->syntax_error = TRUE;
	return ;
}

void	error_grammar(char *message, t_values *vals)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("syntax error near unexpected token `", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
	vals->last_exit_code = 1;
	vals->syntax_error = TRUE;
	return ;
}

void	error_io(char *message, t_values *vals)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	perror(message);
	vals->execute_error = TRUE;
	vals->last_exit_code = 1;
	return ;
}

void	error_command(char *command, char *arg, char *message)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (command != NULL)
	{
		ft_putstr_fd(command, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (arg != NULL)
	{
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (message != NULL)
		ft_putendl_fd(message, STDERR_FILENO);
	return ;
}
