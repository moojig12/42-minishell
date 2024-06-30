/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:38:53 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/06/30 23:20:32 by yjinnouc         ###   ########.fr       */
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

void	signals_process(int signum)
{
	if (signum == SIGINT)
	{
		rl_on_new_line();
		ft_putendl_fd("", STDERR_FILENO);
		rl_replace_line("", 0);
		rl_redisplay();
	}
	return;
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
	return (SUCCESS);
}
