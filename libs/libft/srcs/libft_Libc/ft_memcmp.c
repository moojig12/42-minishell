/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:02:35 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 01:43:44 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - Libc function
DESCRIPTION
	The memcmp() function compares the first n bytes (each interpreted as
	unsigned char) of the memory areas s1 and s2.
RETURN VALUE
	The memcmp() function returns an integer less than, equal to, or greater
	than zero if the first n bytes of s1 is found, respectively, to be less
	than, to match, or be greater than the first n bytes of s2.

	For a nonzero return value, the sign is determined by the sign of the
	difference between the first pair of bytes (interpreted as unsigned char)
	that differ in s1 and s2.

	If n is zero, the return value is zero.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
