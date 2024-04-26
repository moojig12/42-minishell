/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:31:50 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/21 13:11:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*exit process with perror*/
/*just copy from jini's pipex*/
void	exit_with_perror(char *message, char **array, char *str)
{
	ft_putstr_fd("minishell: ", 2);
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
void	exit_without_perror(char *message1, char *file_or_cmd, \
			char **array, char *str)
{
	ft_putstr_fd("minishell: ", 2);
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
