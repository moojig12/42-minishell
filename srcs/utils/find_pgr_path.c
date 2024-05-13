/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pgr_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:28:21 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/13 00:43:22 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*https://42born2code.slack.com/archives/C04C5N7EWS2/p1706306451974049
?thread_ts=1706292510.715149&cid=C04C5N7EWS2*/

#include "minishell.h"

char	*find_pgr_in_path_list(char *pgr_name, char **env_path_list)
{
	int		i;
	char	*path;
	char	*pgr_path;

	i = 0;
	while (env_path_list[i] != NULL)
	{
		path = ft_strjoin(env_path_list[i++], "/");
		pgr_path = ft_strjoin(path, pgr_name);
		free(path);
		if (access(pgr_path, X_OK) == SUCCESS)
			return (pgr_path);
		free(pgr_path);
	}
	return (NULL);
}

<<<<<<< HEAD
char	*find_pgr(char *pgr_name)
=======
char	*find_pgr(char *pgr_name, t_values *vals)
>>>>>>> 84e2675 (improve these)
{
	char	**env_path_list;
	char 	*pgr_path;

	if (access(pgr_name, F_OK | X_OK) == 0)
		return (pgr_name);
	if (is_builtin(pgr_name))
		return (pgr_name);
<<<<<<< HEAD
	env_path_list = get_env_elements_array("PATH");
=======
	env_path_list = get_env_elements_array(vals->env, "PATH");
>>>>>>> 84e2675 (improve these)
	if (env_path_list == NULL)
		return (NULL);
	pgr_path = find_pgr_in_path_list(pgr_name, env_path_list);
	free_array(env_path_list);
	if (pgr_path != NULL)
		return (pgr_path);
	return (NULL);
}
