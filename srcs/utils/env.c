/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:17:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/13 01:05:51 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Function for get env value and return as array.
<<<<<<< HEAD
char	**get_env_elements_array(char *key)
=======
char	**get_env_elements_array(char **env, char *key)
>>>>>>> 84e2675 (improve these)
{
	char	*value_str;
	char	**element_list;

<<<<<<< HEAD
	value_str = getenv(key);
	if (key == NULL)
		return (NULL);
	return (value_str);
=======
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
>>>>>>> 84e2675 (improve these)
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

int	count_env_key(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0' && *str != ' ' && *str != '\'' && *str != '"')
	{
		str++;
		i++;
	}
	return (i);
}

// replace env variable when str[start] is '$'
char	*replace_env_var(char *str, int start, t_values *vals)
{
	int		key_len;
	char	*key;
	char	*val;
	char	*replaced;
	int		start_latter;

	if (str[start + 1] == '?')
	{
		key_len = 1;
		key = ft_strdup("?");
		val = ft_itoa(vals->last_error_code);
	}
	else
	{
		key_len = count_env_key(str + start + 1);
		key = ft_substr(str, start + 1, key_len);
		val = getenv(key);
	}
	free(key);
	start_latter = start + key_len + 1;
	replaced = ft_3strjoin(ft_substr(str, 0, start), val, str + start_latter);
	free(str);
	return (replaced);
}
