/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:05:27 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/09 16:01:30 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

