/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:08:08 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/28 14:45:22 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - not in libc
Parameters
	s: The string on which to iterate.
	f: The function to apply to each character.
Return value None
External functs. None
Description
	Applies the function ’f’ on each character of the string passed as argument,
	passing its index as first argument. Each character is passed by address to
	’f’ to be modified if necessary.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	count;

	count = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[count] != '\0')
	{
		(*f)(count, &s[count]);
		count++;
	}
	return ;
}
