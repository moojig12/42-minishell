/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:17:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/10 15:32:18 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_env_var(char *str, char *key, char	*val, int start)
{
	int		key_len;
	char	*head;
	int		tail_start;
	char	*replaced;

	if (key[0] == '?')
		key_len = 1;
	else
		key_len = ft_strlen(key);
	tail_start = start + 1 + key_len;
	head = ft_substr(str, 0, start);
	replaced = ft_3strjoin(head, val, str + tail_start);
	free(str);
	if (val != NULL)
		free(val);
	free(head);
	return (replaced);
}

// replace env variable when str[start] is '$'
// FIX: fixed memleak but too messy
char	*replace_wrapper(char *str, int start, t_values *vals)
{
	char	*key;
	char	*val;
	char	*replaced;

	if (str[start + 1] == '?')
	{
		key = ft_strdup("?");
		val = ft_itoa(vals->last_exit_code);
	}
	else
	{
		key = ft_substr(str, start + 1, count_env_key(str + start + 1));
		if (get_env_str(vals->env, key) == NULL)
			val = NULL;
		else
			val = ft_strdup(get_env_str(vals->env, key));
	}
	replaced = replace_env_var(str, key, val, start);
	free(key);
	return (replaced);
}
