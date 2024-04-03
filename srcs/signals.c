/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:38:53 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/03 19:37:43 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signals_process_exit(int signum)
{
	if (signum == SIGINT)
	{
		rl_done = 1;
		rl_event_hook = 0;
	}
}

int		signals_handler(void)
{
	signal(SIGINT, signals_process_exit);
	// signal(SIGQUIT, signal_handler_exit);
	return (SUCCESS);
}