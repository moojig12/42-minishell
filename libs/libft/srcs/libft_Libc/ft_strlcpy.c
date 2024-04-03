/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:50:30 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/02 09:41:36 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - Libc function
DESCRIPTION
	The strlcpy() and strlcat() functions copy and concatenate strings
	respectively. They are designed to be safer, more consistent, and less error
	prone replacements for strncpy(3) and strncat(3). Unlike those functions,
	strlcpy() and strlcat() take the full size of the buffer (not just the
	length) and guarantee to NUL-terminate the result (as long as size is larger
	than 0 or, in the case of strlcat(), as long as there is at least one byte
	free in dst). Note that a byte for the NUL should be included in size. Also
	note that strlcpy() and strlcat() only operate on true “C” strings. This
	means that for strlcpy() src must be NUL-terminated and for strlcat() both
	src and dst must be NUL-terminated.

	The strlcpy() function copies up to size - 1 characters from the
	NUL-terminated string src to dst, NUL-terminating the result.
	...
RETURN VALUES
	The strlcpy() and strlcat() functions return the total length of the string
	they tried to create. For strlcpy() that means the length of src. For
	strlcat() that means the initial length of dst plus the length of src.
	While this may seem somewhat confusing, it was done to make truncation
	detection simple.

	Note, however, that if strlcat() traverses size characters without finding a
	NUL, the length of the string is considered to be size and the destination
	string will not be NUL-terminated (since there was no space for the NUL).
	This keeps strlcat() from running off the end of a string. In practice this
	should not happen (as it means that either size is incorrect or that dst is
	not a proper “C” string). The check exists to prevent potential security
	problems in incorrect code.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	count;
	unsigned int	src_len;

	count = 0;
	src_len = ft_strlen(src);
	if (size == 0)
	{
		return (src_len);
	}
	while (src[count] != 0 && count < size - 1)
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = 0;
	return (src_len);
}
