/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:50:12 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/02 09:43:01 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - Libc function
DESCRIPTION
	The strdup() function returns a pointer to a new string which is a duplicate
	of the string s. Memory for the new string is obtained with malloc(3), and
	can be freed with free(3).

	The strndup() function is similar, but copies at most n bytes. If s is
	longer than n, only n bytes are copied, and a terminating null byte ('\0')
	is added.
	...
RETURN VALUE
	On success, the strdup() function returns a pointer to the duplicated
	string. It returns NULL if insufficient memory was available, with errno
	set to indicate the cause of the error.
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	length;
	char			*ptr;

	length = ft_strlen(s);
	ptr = (char *) malloc((length + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s, length);
	ptr[length] = 0;
	return (ptr);
}
