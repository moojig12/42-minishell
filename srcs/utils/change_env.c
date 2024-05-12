/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:10:13 by root              #+#    #+#             */
/*   Updated: 2024/05/12 16:14:20 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_pwd(t_values *vals)
{
	char	*new_pwd;
	char	*temp;
	int		i;

	i = 0;
	temp = getcwd(NULL, 0);
	new_pwd = ft_strjoin("PWD=", temp);
	while (ft_strncmp(vals->env[i], "PWD", 3))
	{
		i++;
	}
	printf("*vals->env: %s\n", vals->env[i]);
	free(vals->env[i]);
	vals->env[i] = ft_strdup(new_pwd);
	free(new_pwd);
	free(temp);
}

//	removes variable by free'ing and decrementing each index
void	remove_env(t_values *vals, char *target)
{
	int	i;

	i = 0;
	while (ft_strncmp(vals->env[i], target, ft_strlen(target)))
		i++;
}

void	add_env(t_values *vals, char *target)
{
	char	**new;
	int	i;
	int	j;

	i = 0;
	printf("%s\n", target);
	while (vals->env[i])
	{
		i++;
	}
	new = (char **)malloc((i + 2) * sizeof(char *));
	j = 0;
	while (j < i)
	{
		new[j] = vals->env[j];
		j++;
	}
}

void	change_env(t_values *vals, char *target, char *operation)
{
	// selection of operation
	if (!ft_strcmp("CD_UPDATE", operation)) 
		update_pwd(vals);
	else if (!ft_strcmp("REMOVE_ENV", operation))
		remove_env(vals, target);
	else if (!ft_strcmp("ADD_ENV", operation))
		add_env(vals, target);
	else
		return ;
}
