/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:09:20 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 20:12:10 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %u Prints an unsigned decimal (base 10) number.
// %x Prints a number in hexadecimal (base 16) lowercase format
// %X Prints a number in hexadecimal (base 16) uppercase format.

#include "libft.h"

int	ft_printf_unsigned(unsigned long nb, int base, char *digits)
{
	int	count;

	count = 0;
	if (nb >= (unsigned long) base)
	{
		count += ft_printf_unsigned(nb / (unsigned long) base, base, digits);
		count += ft_printf_unsigned(nb % (unsigned long) base, base, digits);
	}
	else
		count += write(1, &(digits[nb]), 1);
	return (count);
}
