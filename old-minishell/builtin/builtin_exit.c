/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:05:27 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/18 10:20:05 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
exit with no options

exit: exit [n]
	Exit the shell.

	Exits the shell with a status of N.  If N is omitted, the exit status
	is that of the last command executed.
*/

int	builtin_exit(char **argv, t_values *vals)
{
	free_vals_elements(vals);
	free_array(argv);
	rl_event_hook = NULL;
	exit (0);
	
	// *Fix this later*
	/* if (argv[1] != NULL)
		exit (ft_atoi(argv[1]));
	else
		exit (0); */
}
