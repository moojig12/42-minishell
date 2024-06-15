#include "minishell_r.h"

void	signal_handler(int signum)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_handler_child(int num)
{
	(void)num;
	rl_on_new_line();
}

void	prepare_signals()
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, NULL);
}

void	prepare_signals_child()
{
	signal(SIGINT, signal_handler_child);
	signal(SIGQUIT, signal_handler_child);
}

void	preparation_process(void)
{
	using_history();
	read_history(".minishell_history");
	rl_outstream = stderr;
	rl_event_hook = prepare_signals;
}