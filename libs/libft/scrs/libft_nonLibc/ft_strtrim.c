/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:08:30 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 02:04:35 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - not in libc
Parameters
	s1: The string to be trimmed.
	set: The reference set of characters to trim.
Return value
	The trimmed string. NULL if the allocation fails.
External functs. malloc
Description
	Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
	specified in ’set’ removed from the beginning and the end of the string.
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		s1_length;
	int		start_count;
	int		end_count;

	if (s1 == 0 || set == 0)
		return (0);
	start_count = 0;
	s1_length = ft_strlen(s1);
	while (ft_strchr(set, s1[start_count]) != 0 && start_count < s1_length)
		start_count++;
	end_count = s1_length;
	while (ft_strchr(set, s1[end_count]) != 0 && start_count < end_count)
		end_count--;
	ptr = ft_substr(s1, start_count, end_count - start_count + 1);
	return (ptr);
}
