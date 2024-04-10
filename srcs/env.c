/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:17:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/09 16:02:57 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Functionfor get env value and return as array.
*/
char	**get_env_elements(char **env, char *key)
{
	int		i;
	int		len_key;
	char	*value_str;
	char	**element_list;

	len_key = ft_strlen(key);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], key, len_key) == 0)
		{
			value_str = &env[i][len_key];
			element_list = ft_split(value_str, ':');
			return (element_list);
		}
		i++;
	}
	return (NULL);
}

char	*get_env_str(char **env, char *key)
{
	int		i;
	int		len_key;
	char	*value_str;

	len_key = ft_strlen(key);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], key, len_key) == 0)
		{
			value_str = &env[i][len_key + 1];
			return (value_str);
		}
		i++;
	}
	return (NULL);
}