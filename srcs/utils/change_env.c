/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:10:13 by root              #+#    #+#             */
/*   Updated: 2024/05/11 22:54:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_pwd(char ***env)
{
	char	*new_pwd;
	char	*temp;

	temp = getcwd(NULL, 0);
	new_pwd = ft_strjoin("PWD=", temp);
	while (!ft_strncmp(**env, "PWD", 3))
		env++;
	free(**env);
	**env = ft_strdup(new_pwd);
	free(new_pwd);
	free(temp);
}

//	removes variable by free'ing and decrementing each index
void	remove_env(char ***env, char *target)
{
	while (!ft_strncmp(**env, target, ft_strlen(target)))
		env++;
}

void	add_env(char ***env, char *target)
{
	char	**new;
	int	i;
	int	j;

	i = 0;
	printf("%s\n", target);
	while (*env[i])
	{
		i++;
	}
	new = (char **)malloc((i + 2) * sizeof(char *));
	j = 0;
	while (j < i)
	{
		new[j] = *env[j];
		j++;
	}
}

void	change_env(char ***env, char *target, char *operation)
{
	// selection of operation
	if (!ft_strcmp("CD_UPDATE", operation)) 
		update_pwd(env);
	else if (!ft_strcmp("REMOVE_ENV", operation))
		remove_env(env, target);
	else if (!ft_strcmp("ADD_ENV", operation))
		add_env(env, target);
	else
		return ;
}
