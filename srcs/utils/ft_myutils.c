/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:17:53 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/09 15:51:27 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (TRUE);
	else
		return (FALSE);
}

char *ft_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_ispathkey(char *key)
{
	int	i;

	i = 0;
	while (key[i])
	{
		if (ft_isalnum(key[i]) == FALSE && key[i] != '_')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
