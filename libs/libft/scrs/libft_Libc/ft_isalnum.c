/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:30:51 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 01:42:58 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - Libc function
DESCRIPTION
	checks for an alphanumeric character; it is equivalent to
	(isalpha(c) || isdigit(c)).
RETURN VALUE
	The values returned are nonzero if the character c falls into the tested
	class, and zero if not.
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) == 0 && ft_isalpha(c) == 0)
		return (0);
	return (1);
}

/*
#include <stdio.h>
#include <unistd.h>

int ft_isalnum(char *str);

int main(void){
	char str_a[] = "12345";
	char str_b[] = "I2345";
	char str_null[] = "";
	int ans_a;
	int ans_b;
	int ans_null;

	write(1, str_a, 5); printf("\n");
	write(1, str_b, 5); printf("\n");
	write(1, str_null, 1); printf("\n");

	ans_a = ft_isalnum(str_a);
	ans_b = ft_isalnum(str_b);
	ans_null = ft_isalnum(str_null);

	printf("%d\n", ans_a);
	printf("%d\n", ans_b);   
	printf("%d\n", ans_null);

	return (0);
};
*/