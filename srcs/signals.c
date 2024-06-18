/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:38:53 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/06/18 06:52:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signals_process_np(int signum)
{
	if (signum == SIGINT)
	{
		rl_on_new_line();
		ft_putchar_fd('\n', 1); //TODO: this is ugly. Fix it.
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
	{
		return ;
	}
}

//	TODO: Add tokens as param in signal handler for SIGQUIT and free tokens before exit

int	signals_handler(void)
{
	signal(SIGINT, signals_process_np);
	signal(SIGQUIT, signals_process_np);
	return (SUCCESS);
}
