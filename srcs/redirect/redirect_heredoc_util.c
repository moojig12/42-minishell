/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/12 22:27:58 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int is_delimiter_quoted(char *delimiter)
// {
// 	if (delimiter[0] == '\'' || delimiter[0] == '"')
// 		return (TRUE);
// 	return (FALSE);
// }

// int	process_quoted_delimiter(char *delimiter)
// {
// 	bool	single_quoted;
// 	bool	double_quoted;
// 	int		i;
// 	int		quoted;

// 	single_quoted = FALSE;
// 	double_quoted = FALSE;
// 	i = 0;
// 	while (delimiter[i] != '\0')
// 	{
// 		if (delimiter[i] == '\'' && !double_quoted)
// 		{
// 			single_quoted = !single_quoted;
// 			quoted = TRUE;
// 		}
// 		if (delimiter[i] == '"' && !single_quoted)
// 		{
// 			double_quoted = !double_quoted;
// 			quoted = TRUE;
// 		}
// 		i++;
// 	}
// 	return (SUCCESS);
// }

// char	*process_env_heredocs(char *line, t_values *vals)
// {
// 	bool	single_quoted;
// 	bool	double_quoted;
// 	int		i;

// 	single_quoted = FALSE;
// 	double_quoted = FALSE;
// 	i = 0;
// 	while (line[i] != '\0')
// 	{
// 		if (line[i] == '\'' && !double_quoted)
// 			single_quoted = !single_quoted;
// 		if (line[i] == '"' && !single_quoted)
// 			double_quoted = !double_quoted;
// 		if (line[i] == '$' && !single_quoted)
// 			line = replace_env_var(line, i, vals);
// 		i++;
// 	}
// 	return (line);
// }
