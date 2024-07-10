/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:17:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/08 14:05:52 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// replace env variable when str[start] is '$'
// FIX: fixed memleak but too messy
char	*replace_env_var(char *str, int start, t_values *vals)
{
	int		key_len;
	char	*key;
	char	*val;
	char	*replaced;
	int		start_latter;
	char	*first;

	if (str[start + 1] == '?')
	{
		key_len = 1;
		key = ft_strdup("?");
		val = ft_itoa(vals->last_exit_code);
	}
	else
	{
		key_len = count_env_key(str + start + 1);
		key = ft_substr(str, start + 1, key_len);
		val = ft_strdup(getenv(key));
	}
	free(key);
	start_latter = start + key_len + 1;
	first = ft_substr(str, 0, start);
	replaced = ft_3strjoin(first, val, str + start_latter);
	free(str);
	free(val);
	free(first);
	return (replaced);
}
