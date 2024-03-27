/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:49:56 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/02 09:44:20 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - Libc function
DESCRIPTION
	The strchr() function returns a pointer to the first occurrence of the
	character c in the string s.
	...
	Here "character" means "byte"; these functions do not work with wide or
	multibyte characters.
RETURN VALUE
	The strchr() and strrchr() functions return a pointer to the matched
	character or NULL if the character is not found. The terminating null byte
	is considered part of the string, so that if c is specified as '\0', these
	functions return a pointer to the terminator.
	...
*/

char	*ft_strchr(const char *s, int c)
{
	unsigned char	tmp_c;

	tmp_c = (unsigned char) c;
	while (*s != '\0' && *s != tmp_c)
		s++;
	if (*s == tmp_c)
		return ((char *)s);
	return (0);
}

/*
#include <stdio.h>

int main (void)
{
	const char *s = "MMMOOONNNKKKEEEYYY";
	printf("ans:%s\n", ft_strchr(s, 'N'));
	return (0);
}
*/