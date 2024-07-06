/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:00:18 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/12 16:58:42 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
env with no options or arguments

TODO: no help?
*/
int	builtin_env(t_values *vals)
{
	int	i;

	i = 0;
	while (vals->env[i])
	{
		ft_putendl_fd(vals->env[i], 1);
		i++;
	}
	return (EXIT_SUCCESS);
}
