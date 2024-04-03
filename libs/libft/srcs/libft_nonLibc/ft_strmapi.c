/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:08:23 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 01:58:59 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - not in libc
Parameters
	s: The string on which to iterate.
	f: The function to apply to each character.
Return value 
	The string created from the successive applications of ’f’.
	Returns NULL if the allocation fails.
External functs. malloc
Description
	Applies the function ’f’ to each character of the string ’s’, and passing
	its index as first argument to create a new string (with malloc(3))
	resulting from successive applications of ’f’.
*/

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		count;

	count = 0;
	if (s == 0 || f == 0)
		return (0);
	ptr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (s[count] != '\0')
	{
		ptr[count] = (*f)(count, s[count]);
		count++;
	}
	ptr[count] = '\0';
	return (ptr);
}
