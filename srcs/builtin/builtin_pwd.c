/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:59:37 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/01 08:54:11 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
pwd with no options

pwd: pwd [-LP]
	Print the name of the current working directory.

	Options:
		-L	print the value of $PWD if it names the current working directory
		-P	print the physical directory, without any symbolic links
	By default, `pwd' behaves as if `-L' were specified.

	Exit Status:
	Returns 0 unless an invalid option is given or the current directory
	cannot be read.
*/

int	builtin_pwd(void) //char **env
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		ft_putstr_fd("error: ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		return (FAILURE);
	}
	ft_putendl_fd(pwd, 1);
	free(pwd);
	return (SUCCESS);
}
