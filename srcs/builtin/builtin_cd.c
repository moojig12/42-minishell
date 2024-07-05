/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:27:20 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/05 13:32:35 by nmandakh         ###   ########.fr       */
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

int	chdir_to_oldpwd(t_values *vals)
{
	int		i;
	int		ret;
	char	*dest;

	i = 0;
	while (ft_strncmp(vals->env[i], "OLDPWD", 6))
		i++;
	if (vals->env[i])
	{
		dest = ft_substr(vals->env[i], 7, INT_MAX);
		ret = chdir(dest);
		free(dest);
		return (ret);
	}
	else
		return (EXIT_FAILURE);
}

int	builtin_cd(char **args, t_values *vals)
{
    int	ret;
	int	argc;

	argc = count_str_array(args);
	if (argc != 2)
	{
        ft_putendl_fd("cd: too many arguments", STDERR_FILENO);
        return (EXIT_FAILURE);
    }
	if (ft_strncmp("-", args[1], 2))
		ret = chdir(args[1]);
	else
		ret = chdir_to_oldpwd(vals);
	if (ret != 0)
	{
        perror("cd");
		return (EXIT_FAILURE);
    }
	change_env("PWD", NULL, "PWD_UPDATE", vals);
    return (EXIT_SUCCESS);
}
