/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:05:27 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/12 17:23:52 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
export with no options
export: export [-fn] [name[=value] ...] or export -p
	Set export attribute for shell variables.

	Marks each NAME for automatic export to the environment of subsequently
	executed commands.  If VALUE is supplied, assign VALUE before exporting.

	Options:
	-f	refer to shell functions
	-n	remove the export property from each NAME
	-p	display a list of all exported variables and functions

	An argument of `--' disables further option processing.

	Exit Status:
	Returns success unless an invalid option is given or NAME is invalid.
*/
int	check_syntax(char *var)
{
	if (!var)
		return (FAILURE);
	return (SUCCESS);
}
	// Adds variable from export arg to env
	// Multiple variable exporting *TO BE ADDED!*
int	builtin_export(char **argv, t_values *vals)
{
	char	*variable;
	int	i;

	i = 1;
	variable = ft_strdup(argv[i]);
	if (!check_syntax(variable))
		return (FAILURE);
	change_env(vals, variable, "ADD_ENV");
	return (SUCCESS);
}