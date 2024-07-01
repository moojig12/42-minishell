/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_libs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:44:09 by nmandakh          #+#    #+#             */
/*   Updated: 2024/07/01 09:32:56 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_LIBS_H
# define MINISHELL_LIBS_H 1

# include <stdbool.h>			// boolean
# include <stdio.h>				// printf
# include <readline/readline.h>	// readline
// rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history
# include <readline/history.h>
# include <stdlib.h>			// malloc, free, exit
// access, fork, execve, getcwd, chdir, close, read,
// write, pipe, dup, dup2, wait, waitpid
# include <unistd.h>
# include <fcntl.h>				// open
// signal, sigaction, sigemptyset, sigaddset, kill
# include <signal.h>
// wait, waitpid, fork, access, open, stat, lstat, fstat,
// dup, dup2, pipe, opendir, readdir, closedir
# include <sys/types.h>
# include <sys/wait.h>			// wait, waitpid, wait3, wait4
# include <sys/stat.h>			// stat, lstat, fstat, unlink
# include <dirent.h>			// opendir, readdir, closedir
# include <string.h>			// strerror
# include <errno.h>				// perror
# include <termios.h>			// tcsetattr, tcgetattr
# include <unistd.h>			// isatty, ttyname, ttyslot, ioctl
// tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <curses.h>
# include <stdlib.h>			// getenv
# include <limits.h>
# include "libft.h"
# include <stdbool.h>

#endif
