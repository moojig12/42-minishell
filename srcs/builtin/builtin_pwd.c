/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:59:37 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/08 13:59:17 by nmandakh         ###   ########.fr       */
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

int	builtin_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		ft_putstr_fd("error: ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_putendl_fd(pwd, 1);
	free(pwd);
	return (EXIT_SUCCESS);
}
