/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:27:20 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/01 08:54:03 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
cd with only a relative or absolute path

cd: cd [-L|[-P [-e]] [-@]] [dir]
	Change the shell working directory.

	Change the current directory to DIR.  The default DIR is the value of the
	HOME shell variable.

	The variable CDPATH defines the search path for the directory containing
	DIR.  Alternative directory names in CDPATH are separated by a colon (:).
	A null directory name is the same as the current directory.  If DIR begins
	with a slash (/), then CDPATH is not used.

	If the directory is not found, and the shell option `cdable_vars' is set,
	the word is assumed to be  a variable name.  If that variable has a value,
	its value is used for DIR.

	Options:
	-L	force symbolic links to be followed: resolve symbolic
		links in DIR after processing instances of `..'
	-P	use the physical directory structure without following
		symbolic links: resolve symbolic links in DIR before
		processing instances of `..'
	-e	if the -P option is supplied, and the current working
		directory cannot be determined successfully, exit with
		a non-zero status
	-@	on systems that support it, present a file with extended
		attributes as a directory containing the file attributes

	The default is to follow symbolic links, as if `-L' were specified.
	`..' is processed by removing the immediately previous pathname component
	back to a slash or the beginning of DIR.

	Exit Status:
	Returns 0 if the directory is changed, and if $PWD is set successfully when
	-P is used; non-zero otherwise.
*/

int	builtin_cd(char **args, t_values *vals)
{
    int	ret;
	int argc;

	argc = count_str_array(args);
	if (argc != 2)
	{
        ft_putendl_fd("cd: too many arguments", STDERR_FILENO);
        return (EXIT_FAILURE);
    }
	ret = chdir(args[1]);
	if (ret != 0)
	{
        perror("cd");
		return (EXIT_FAILURE);
    }
	change_env("PWD", NULL, "PWD_UPDATE", vals);
    return (EXIT_SUCCESS);
}
