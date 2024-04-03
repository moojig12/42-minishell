/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:50:59 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/02 09:34:45 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - Libc function
DESCRIPTION
	The strnstr() function locates the first occurrence of the null-terminated
	string little in the string big, where not more than len characters are
	searched. Characters that appear after a ‘\0’ character are not searched.
	Since the strnstr() function is a FreeBSD specific API, it should only be
	used when portability is not a concern.
RETURN VALUES
	If little is an empty string, big is returned; if little occurs nowhere in
	big, NULL is returned; otherwise a pointer to the first character of the
	first occurrence of little is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	start;
	unsigned int	count;

	start = 0;
	if (little[0] == 0)
		return ((char *) big);
	while (big[start] && start < len)
	{
		count = 0;
		while (big[start + count] == little[count] && start + count < len)
		{
			if (little[count + 1] == 0)
				return ((char *)(big + start));
			count++;
		}
		start++;
	}
	return (0);
}
