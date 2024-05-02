/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:05:27 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/09 16:01:35 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
unset with no options
unset: unset [-f] [-v] [-n] [name ...]
	Unset values and attributes of shell variables and functions.

	For each NAME, remove the corresponding variable or function.

	Options:
	-f	treat each NAME as a shell function
	-v	treat each NAME as a shell variable
	-n	treat each NAME as a name reference and unset the variable itself
		rather than the variable it references

	Without options, unset first tries to unset a variable, and if that fails,
	tries to unset a function.

	Some variables cannot be unset; also see `readonly'.

	Exit Status:
	Returns success unless an invalid option is given or a NAME is read-only.
*/

/*
exit with no options
exit: exit [n]
	Exit the shell.

	Exits the shell with a status of N.  If N is omitted, the exit status
	is that of the last command executed.
*/
