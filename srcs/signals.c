/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:38:53 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/05 13:12:48 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
• In interactive mode:
◦ ctrl-C displays a new prompt on a new line.
◦ ctrl-D exits the shell.
◦ ctrl-\ does nothing
*/

void	sig_ignore(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	rl_on_new_line();
}

void	signals_hander_ignore(void)
{
	signal(SIGINT, sig_ignore);
}

void	signals_process(int signum)
{
	if (signum == SIGINT)
	{
		rl_on_new_line();
		ft_putendl_fd("", STDERR_FILENO);
		rl_replace_line("", 0);
		rl_redisplay();
	}
	return ;
}

/*
this function makes
- ctrl-C = assign SIGINT to signals_process() function
	(displays a new prompt on a new line.)
- ctrl-\ = assign SIGQUIT to SIG_IGN (=does nothing)
- ctrl-D = no assign changed but calls exit with "input == NULL" in main()

fyi: default key bindings
- ctrl-C = SIGINT
- ctrl-\ = SIGQUIT
- ctrl-D = EOF
*/
int	signals_handler(void)
{
	signal(SIGINT, signals_process);
	signal(SIGQUIT, SIG_IGN);
	return (EXIT_SUCCESS);
}
