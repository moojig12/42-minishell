/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:09:20 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 20:12:05 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %p The void * pointer argument has to be printed in hexadecimal format.

#include "libft.h"

int	ft_printf_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		count += ft_printf_str("(nil)");
	else
	{
		count += ft_printf_str("0x");
		count += ft_printf_unsigned((unsigned long) ptr, 16,
				"0123456789abcdef");
	}
	return (count);
}
