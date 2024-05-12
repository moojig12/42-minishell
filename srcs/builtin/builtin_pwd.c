/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:59:37 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/12 09:42:27 by root             ###   ########.fr       */
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
		printf("error: %s\n", strerror(errno));
		return (FAILURE);
	}
	// TODO: need renew env pwd ???
	printf("%s\n", pwd);
<<<<<<< HEAD
	free(pwd);
=======
  free(pwd);
>>>>>>> 0f12847 (Update env pwd functional now)
	return (SUCCESS);
}
