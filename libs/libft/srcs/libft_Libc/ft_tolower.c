/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:57:04 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/02 09:32:10 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - Libc function
DESCRIPTION
	If c is an uppercase letter, tolower() returns its lowercase equivalent, if
	a lowercase representation exists in the current locale. Otherwise, it
	returns c. The tolower_l() function performs the same task, but uses the
	locale referred to by the locale handle locale.

RETURN VALUE
	The value returned is that of the converted letter, or c if the conversion
	was not possible.
*/

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}
