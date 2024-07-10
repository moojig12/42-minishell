/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:03:03 by nmandakh          #+#    #+#             */
/*   Updated: 2024/07/08 14:03:51 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_env_key(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0' && \
		*str != ' ' && \
		*str != '\'' && \
		*str != '"' && \
		*str != '$')
	{
		str++;
		i++;
	}
	return (i);
}

// Function for get env value and return as array.
char	**get_env_elements_array(char **env, char *key)
{
	int		len_key;
	int		i;
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
		if (ft_strncmp(env[i], key, len_key) == 0 && \
			env[i][len_key] == '=')
		{
			value_str = &env[i][len_key + 1];
			return (value_str);
		}
		i++;
	}
	return (NULL);
}
