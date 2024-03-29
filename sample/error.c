/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:31:50 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/03/29 12:18:01 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*exit process with perror*/
/*just copy from jini's pipex*/
void	exit_wi_perr(char *message, char **array, char *str)
{
	ft_putstr_fd("pipex: ", 2);
	perror(message);
	ft_putchar_fd('\n', 2);
	if (array != NULL)
		free_array(array);
	if (str != NULL)
		free(str);
	if (errno)
		exit (errno);
	exit (EXIT_FAILURE);
}

/*exit process without perror*/
/*just copy from jini's pipex*/
void	exit_wo_perr(char *message1, char *file_or_cmd, \
			char **array, char *str)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(message1, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file_or_cmd, 2);
	ft_putchar_fd('\n', 2);
	if (array != NULL)
		free_array(array);
	if (str != NULL)
		free(str);
	if (ft_strncmp(message1, "command not found", 17) == 0)
		exit(127);
	if (errno)
		exit (errno);
	exit (EXIT_FAILURE);
}