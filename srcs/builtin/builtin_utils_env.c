/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:10:13 by root              #+#    #+#             */
/*   Updated: 2024/07/04 08:41:59 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_pwd(t_values *vals)
{
	char	*new_pwd;
	char	*old_pwd;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = getcwd(NULL, 0);
	new_pwd = ft_strjoin("PWD=", temp);
	while (ft_strncmp(vals->env[i], "PWD=", 4))
		i++;
	while (ft_strncmp(vals->env[j], "OLDPWD", 6))
		j++;
	old_pwd = ft_strdup(vals->env[i]);
	if (vals->env[j])
		free(vals->env[j]);
	vals->env[j] = ft_strjoin("OLD", old_pwd);
	free(old_pwd);
	free(vals->env[i]);
	vals->env[i] = ft_strdup(new_pwd);
	free(new_pwd);
	free(temp);
}

int	update_env(char *key, char *value, t_values *vals)
{
	int	count;

	count = 0;
	while (vals->env[count])
	{
		if (ft_strncmp(vals->env[count], key, ft_strlen(key)) == 0 && \
			vals->env[count][ft_strlen(key)] == '=')
		{
			free(vals->env[count]);
			vals->env[count] = ft_strdup(value);
			return (EXIT_SUCCESS);
		}
		count++;
	}
	return (EXIT_FAILURE);
}

//	removes variable by free'ing and decrementing each index
void	remove_env(char *key, t_values *vals)
{
	int		count;

	count = 0;
	while (ft_strncmp(vals->env[count], key, ft_strlen(key)) != 0 || \
			vals->env[count][ft_strlen(key)] != '=')
		count++;
	free(vals->env[count]);
	vals->env[count] = vals->env[count + 1];
	count++;
	while (vals->env[count])
	{
		vals->env[count] = vals->env[count + 1];
		count++;
	}
	vals->env[count] = NULL;
}

// value must be mallocated in this case
void	add_env(char *value, t_values *vals)
{
	char	**new;
	int		size_env;
	int		count;

	size_env = count_str_array(vals->env);
	new = (char **)malloc((size_env + 2) * sizeof(char *));
	count = 0;
	while (count < size_env)
	{
		new[count] = vals->env[count];
		count++;
	}
	new[count] = ft_strdup(value);
	count++;
	new[count] = NULL;
	free(vals->env);
	vals->env = new;
}

int	change_env(char *key, char *value, char *operation, t_values *vals)
{
	if (!ft_strcmp("PWD_UPDATE", operation) && \
		!ft_strcmp(key, "PWD"))
		update_pwd(vals);
	else if (!ft_strcmp("SET_ENV", operation) && \
		get_env_str(vals->env, key) == NULL)
		add_env(value, vals);
	else if (!ft_strcmp("SET_ENV", operation) && \
		get_env_str(vals->env, key) != NULL)
		update_env(key, value, vals);
	else if (!ft_strcmp("UNSET_ENV", operation) && \
		get_env_str(vals->env, key) != NULL)
		remove_env(key, vals);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
