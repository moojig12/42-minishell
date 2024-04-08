/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:38:53 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/08 19:02:45 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signals_process_np(int signum)
{
	if (signum == SIGINT)
	{
		rl_on_new_line();
		printf("\n"); //TODO: this is ugly. Fix it.
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	signals_handler(void)
{
	signal(SIGINT, signals_process_np);
	signal(SIGQUIT, NULL);
	return (SUCCESS);
}
