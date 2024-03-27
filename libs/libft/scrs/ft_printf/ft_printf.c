/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 23:05:12 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 20:12:17 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/

#include "libft.h"

int	ft_printf_format(const char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_printf_char(va_arg(args, int));
	else if (type == 's')
		count += ft_printf_str(va_arg(args, char *));
	else if (type == 'p')
		count += ft_printf_ptr(va_arg(args, void *));
	else if (type == 'd')
		count += ft_printf_int(va_arg(args, int));
	else if (type == 'i')
		count += ft_printf_int(va_arg(args, int));
	else if (type == 'u')
		count += ft_printf_unsigned((unsigned long) va_arg(args, unsigned int),
				10, "0123456789");
	else if (type == 'x')
		count += ft_printf_unsigned((unsigned long) va_arg(args, unsigned int),
				16, "0123456789abcdef");
	else if (type == 'X')
		count += ft_printf_unsigned((unsigned long) va_arg(args, unsigned int),
				16, "0123456789ABCDEF");
	else if (type == '%')
		count += write(1, &"%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	count;

	if (!format || *format == '\0')
		return (0);
	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += ft_printf_format(*(++format), args);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
