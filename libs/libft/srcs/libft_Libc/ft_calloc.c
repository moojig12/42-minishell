/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:58:35 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 01:42:55 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - Libc function
DESCRIPTION
	...
	The calloc() function allocates memory for an array of nmemb elements of
	size bytes each and returns a pointer to the allocated memory. The memory is
	set to zero. If nmemb or size is 0, then calloc() returns either NULL, or a
	unique pointer value that can later be successfully passed to free(). If the
	multiplication of nmemb and size would result in integer overflow, then
	calloc() returns an error. By contrast, an integer overflow would not be
	detected in the following call to malloc(), with the result that an
	incorrectly sized block of memory would be allocated:
		malloc(nmemb * size);
	...
RETURN VALUE
	The malloc() and calloc() functions return a pointer to the allocated memory,
	which is suitably aligned for any built-in type. On error, these functions
	return NULL. NULL may also be returned by a successful call to malloc() with
	a size of zero, or by a successful call to calloc() with nmemb or size equal
	to zero.
	...
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 0;
		size = 1;
	}
	if (INT_MAX / size < nmemb)
		return (0);
	ptr = (void *) malloc(nmemb * size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
