/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:31:02 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 01:43:01 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - Libc function
DESCRIPTION
	checks for an alphabetic character; in the standard "C" locale, it is
	equivalent to (isupper(c) || islower(c)). In some locales, there may be
	additional characters for which isalpha() is true—letters which are neither
	uppercase nor lowercase.
RETURN VALUE
	The values returned are nonzero if the character c falls into the tested
	class, and zero if not.
*/

int	ft_isalpha(int c)
{
	if ((c < 'A' || 'Z' < c) && (c < 'a' || 'z' < c))
		return (0);
	return (1);
}

/*
#include <stdio.h>
#include <unistd.h>

int ft_isalpha(char *str);

int main(void){
	char str_a[] = "HELLO";
	char str_b[] = "HELL0";
	char str_null[] = "";
	int ans_a;
	int ans_b;
	int ans_null;

	write(1, str_a, 5); printf("\n");
	write(1, str_b, 5); printf("\n");
	write(1, str_null, 1); printf("\n");

	ans_a = ft_isalpha(str_a);
	ans_b = ft_isalpha(str_b);
	ans_null = ft_isalpha(str_null);

	printf("%d\n", ans_a);
	printf("%d\n", ans_b);   
	printf("%d\n", ans_null);

	return (0);
};
*/