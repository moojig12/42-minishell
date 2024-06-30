/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:05:27 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/06/30 23:38:21 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Your shell must implement the following builtins:
- echo with option -n
- cd with only a relative or absolute path
- pwd with no options
- export with no options
- unset with no options
- env with no options or arguments
- exit with no options
*/

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (TRUE);
	if (ft_strcmp(cmd, "cd") == 0)
		return (TRUE);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (TRUE);
	if (ft_strcmp(cmd, "export") == 0)
		return (TRUE);
	if (ft_strcmp(cmd, "unset") == 0)
		return (TRUE);
	if (ft_strcmp(cmd, "env") == 0)
		return (TRUE);
	if (ft_strcmp(cmd, "exit") == 0)
		return (TRUE);
	return (FALSE);
}

int	execute_builtin(char **argv, t_values *vals)
{
	if (ft_strcmp(argv[0], "echo") == 0)
		return (builtin_echo(argv));
	if (ft_strcmp(argv[0], "cd") == 0)
		return (builtin_cd(argv, vals));
	if (ft_strcmp(argv[0], "pwd") == 0)
		return (builtin_pwd());
	if (ft_strcmp(argv[0], "export") == 0)
		return (builtin_export(argv, vals));
	if (ft_strcmp(argv[0], "unset") == 0)
		return (builtin_unset(argv, vals));
	if (ft_strcmp(argv[0], "env") == 0)
		return (builtin_env(vals));
	if (ft_strcmp(argv[0], "exit") == 0)
		return (builtin_exit(argv, vals));
	return (FAILURE);
}
