/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:09:20 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 20:12:02 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %i Prints an integer in base 10
// %d Prints a decimal (base 10) number.

#include "libft.h"

int	ft_printf_int(int nb)
{
	int		count;
	char	digit;

	digit = nb + '0';
	count = 0;
	if (nb == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	else if (nb < 0)
	{
		count += write(1, &*("-"), 1);
		nb *= -1;
		count += ft_printf_int(nb);
	}
	else if (9 < nb)
	{
		count += ft_printf_int(nb / 10);
		count += ft_printf_int(nb % 10);
	}
	else
		count += write(1, &digit, 1);
	return (count);
}
