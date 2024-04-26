/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pgr_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:28:21 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/09 15:10:29 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*https://42born2code.slack.com/archives/C04C5N7EWS2/p1706306451974049
?thread_ts=1706292510.715149&cid=C04C5N7EWS2*/

#include "minishell.h"

char	*find_pgr(char *pgr_name, char **envp)
{
	char	**env_path_list;
	char	*path;
	char	*pgr_path;
	int		i;

	if (access(pgr_name, F_OK | X_OK) == 0)
		return (pgr_name);
	if (is_builtin(pgr_name))
		return (pgr_name);
	env_path_list = get_env_elements(envp, "PATH=");
	if (env_path_list == NULL)
		return (NULL);
	i = 0;
	while (env_path_list[i] != NULL)
	{
		path = ft_strjoin(env_path_list[i++], "/");
		pgr_path = ft_strjoin(path, pgr_name);
		free(path);
		if (access(pgr_path, X_OK) == 0)
		{
			free_array(env_path_list);
			return (pgr_path);
		}
		free(pgr_path);
	}
	free_array(env_path_list);
	return (NULL);
}

