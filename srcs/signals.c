/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:38:53 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/06/25 15:18:55 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signals_process_np(int signum)
{
	(void)signum;
	ft_putchar_fd('\n', 1); //TODO: this is ugly. Fix it.
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	sigquit_process(int signum)
{
	(void)signum;
}
//	TODO: Add tokens as param in signal handler for SIGQUIT and free tokens before exit

int	signals_handler(void)
{
	signal(SIGINT, signals_process_np);
	signal(SIGQUIT, SIG_IGN);
	return (SUCCESS);
}
