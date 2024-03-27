/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:02:23 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 01:43:21 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - Libc function
DESCRIPTION
	The memchr() function scans the initial n bytes of the memory area pointed
	to by s for the first instance of c. Both c and the bytes of the memory area
	pointed to by s are interpreted as unsigned char.
	...
RETURN VALUE
	The memchr() and memrchr() functions return a pointer to the matching byte
	or NULL if the character does not occur in the given memory area.
	...
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
		n--;
	}
	return (0);
}
