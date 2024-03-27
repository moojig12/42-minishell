/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:59:23 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 01:42:50 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - Libc function
DESCRIPTION
	The bzero() function erases the data in the n bytes of the memory starting
	at the location pointed to by s, by writing zeros (bytes containing '\0') to
	that area.
	...
RETURN VALUE
	None.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp_s;

	tmp_s = s;
	while (n > 0)
	{
		*tmp_s++ = 0;
		n--;
	}
	return ;
}
