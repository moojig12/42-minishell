/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:31:47 by nmandakh          #+#    #+#             */
/*   Updated: 2024/07/10 14:32:17 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_and_redirect(t_values *vals, char **argv, char *pgr)
{
	reset_redirect(vals);
	free_array(argv);
	free(pgr);
}

void	free_pipe_vals(t_values *vals, \
	int **pipe_fds_array, int total_commands)
{
	free_int_array(pipe_fds_array, total_commands);
	free_vals_elements(vals);
}
