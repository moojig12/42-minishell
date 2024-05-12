/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:59:37 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/12 16:18:45 by nmandakh         ###   ########.fr       */
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

int	builtin_pwd(char **args) //char **env
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
	free(pwd);
	free_array(args);
	return (SUCCESS);
}
