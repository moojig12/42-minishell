/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:28:21 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/08 17:32:21 by yjinnouc         ###   ########.fr       */
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
	env_path_list = get_env(envp, "PATH=");
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

/*
Functionfor get env value and return as array.
*/
char	**get_env(char **envp, char *key)
{
	int		i;
	int		len_key;
	char	*value_str;
	char	**element_list;

	len_key = ft_strlen(key);
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], key, len_key) == 0)
		{
			value_str = &envp[i][len_key];
			element_list = ft_split(value_str, ':');
			return (element_list);
		}
		i++;
	}
	return (NULL);
}