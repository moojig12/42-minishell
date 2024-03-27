/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:30:41 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 01:43:07 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - Libc function
DESCRIPTION
	checks for a digit (0 through 9).
RETURN VALUE
	The values returned are nonzero if the character c falls into the tested
	class, and zero if not.
*/

int	ft_isdigit(int c)
{
	if (c < '0' || '9' < c)
		return (0);
	return (1);
}
