/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:05:27 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/06 17:43:56 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
echo with option -n

echo: echo [-neE] [arg ...]
	Write arguments to the standard output.

	Display the ARGs, separated by a single space character and followed by a
	newline, on the standard output.

	Options:
		-n	do not append a newline
		-e	enable interpretation of the following backslash escapes
		-E	explicitly suppress interpretation of backslash escapes

	`echo' interprets the following backslash-escaped characters:
		\a	alert (bell)
		\b	backspace
		\c	suppress further output
		\e	escape character
		\E	escape character
		\f	form feed
		\n	new line
		\r	carriage return
		\t	horizontal tab
		\v	vertical tab
		\\	backslash
		\0nnn	the character whose ASCII code is NNN (octal).  NNN can be
			0 to 3 octal digits
		\xHH	the eight-bit character whose value is HH (hexadecimal).  HH
			can be one or two hex digits
		\uHHHH	the Unicode character whose value is the hexadecimal value HHHH.
			HHHH can be one to four hex digits.
		\UHHHHHHHH	the Unicode character whose value is the hexadecimal value
			HHHHHHHH. HHHHHHHH can be one to eight hex digits.

	Exit Status:
	Returns success unless a write error occurs.
*/

	// -n Option needs to be implemented later on!

bool	check_string_newl(char *string)
{
	int	i;

	i = 1;
	if (!string)
		return (FALSE);
	else if (ft_strncmp(string, "-n", 2) != 0)
		return (FALSE);
	while (string[i])
	{
		if (string[i] != 'n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_newline(char ***head, char **argv)
{
	int	i;

	i = 1;
	if (check_string_newl(argv[1]))
	{
		while (argv[i])
		{
			i++;
			if (!check_string_newl(argv[i]))
				break ;
		}
	}
	if (argv[i])
	{
		if (i > 0)
			*head += i;
		if (i > 1)
			return (1);
	}
	return (0);
}

int	builtin_echo(char **argv)
{
	char	**head;
	bool	new_l;

	new_l = TRUE;
	head = argv;
	if (check_newline(&argv, argv) == 1)
		new_l = FALSE;
	if (*head == *argv)
		return (EXIT_SUCCESS);
	while (*argv)
	{
		ft_putstr_fd(*argv, STDOUT_FILENO);
		argv++;
		if (*argv)
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if (new_l)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
