/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:17:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/10 16:33:21 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_vars(char *str)
{
	int	i;

	i = 0;
	while (str)
	{
		if (*str == '$')
			i++;
		str++;
	}
	return (i);
}

int	extract_varlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (!ft_isspace(str[i]) || str[i] != '$'))
		i++;
	return (i);
}

void	len_pop(char *str, int *len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i++] == '$')
		{
			len[j++] = extract_varlen(&str[i]);
		}
	}
}

int	*count_varlen(char *str)
{
	int	*len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = (int *)malloc((count_vars(str)) * sizeof(int));
	len_pop(str, len);
	return (len);
}

char	*replace_vars(char *str, char **var, int *len)
{
	char	*result;

	result = (char *)malloc(((ft_strlen(str) - orig_var()) + int_sum()) * sizeof(char))
}
// replace env variable when str[start] is '$'
// FIX: fixed memleak but too messy
char	*replace_env_var(char *str, int start, t_values *vals)
{
	char	**var;
	char	*result;
	int		*len;
	int		i;

	if (!str[start + 1] || ft_isspace(str[start + 1]))
		return (str);
	len = count_varlen(str);
	var = (char **)malloc((count_vars(str)) * sizeof(char *));
	result = replace_vars(str, var, len);
	return (result);
}

