/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:05:27 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/09 16:01:30 by yjinnouc         ###   ########.fr       */
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

/*
cd with only a relative or absolute path
cd: cd [-L|[-P [-e]] [-@]] [dir]
	Change the shell working directory.

	Change the current directory to DIR.  The default DIR is the value of the
	HOME shell variable.

	The variable CDPATH defines the search path for the directory containing
	DIR.  Alternative directory names in CDPATH are separated by a colon (:).
	A null directory name is the same as the current directory.  If DIR begins
	with a slash (/), then CDPATH is not used.

	If the directory is not found, and the shell option `cdable_vars' is set,
	the word is assumed to be  a variable name.  If that variable has a value,
	its value is used for DIR.

	Options:
	-L	force symbolic links to be followed: resolve symbolic
		links in DIR after processing instances of `..'
	-P	use the physical directory structure without following
		symbolic links: resolve symbolic links in DIR before
		processing instances of `..'
	-e	if the -P option is supplied, and the current working
		directory cannot be determined successfully, exit with
		a non-zero status
	-@	on systems that support it, present a file with extended
		attributes as a directory containing the file attributes

	The default is to follow symbolic links, as if `-L' were specified.
	`..' is processed by removing the immediately previous pathname component
	back to a slash or the beginning of DIR.

	Exit Status:
	Returns 0 if the directory is changed, and if $PWD is set successfully when
	-P is used; non-zero otherwise.
*/



/*
export with no options
export: export [-fn] [name[=value] ...] or export -p
	Set export attribute for shell variables.

	Marks each NAME for automatic export to the environment of subsequently
	executed commands.  If VALUE is supplied, assign VALUE before exporting.

	Options:
	-f	refer to shell functions
	-n	remove the export property from each NAME
	-p	display a list of all exported variables and functions

	An argument of `--' disables further option processing.

	Exit Status:
	Returns success unless an invalid option is given or NAME is invalid.
*/