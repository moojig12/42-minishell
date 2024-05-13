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

// Function for get env value and return as array.
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

// get_env_value with getenv() function.
char	*get_env_value(char *key)
{
	char	*value_str;

	value_str = getenv(key);
	if (value_str == NULL)
		return (NULL);
	return (value_str);
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

// replace string (from start to ' or " or space ) to env value in malloced string
// given string  ptr must be freed and replaced with new string
char *replace_env_var(char *str, int start)
{
	char	*temp;
	int		i;
	char 	*key;
	char 	*s1;
	char	*s2;

	temp = str + start;
	i = 0;
	while (*temp != '\0' && *temp != ' ' && *temp != '\'' && *temp != '"')
	{
		temp++;
		i++;
	}
	key = ft_substr(str, start, i);
	s1 = ft_substr(str, 0, start);
	if (ft_strcmp(key, "?") == 0)
		s2 = ft_strjoin(s1, ft_itoa(0)); // TODO: fix to show exit status
	else
		s2 = ft_strjoin(s1, getenv("HOME"));
	free(key);
	free(s1);
	s1 = ft_strjoin(s2, temp);
	free(s2);
	free(str);
	return (s1);
}
