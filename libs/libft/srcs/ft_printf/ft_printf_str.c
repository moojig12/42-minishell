/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:09:20 by yjinnouc          #+#    #+#             */
/*   Updated: 2023/12/02 17:19:33 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %s Prints a string (as defined by the common C convention)

#include "libft.h"

int	ft_printf_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		count += write(1, &(*"(null)"), 6);
	else
	{
		while (*str != '\0')
			count += write(1, &(*str++), 1);
	}
	return (count);
}
