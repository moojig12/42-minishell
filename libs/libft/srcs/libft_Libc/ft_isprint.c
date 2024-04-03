/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:31:15 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 01:43:09 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - Libc function
DESCRIPTION
	checks for any printable character including space.
RETURN VALUE
	The values returned are nonzero if the character c falls into the tested
	class, and zero if not.
*/

int	ft_isprint(int c)
{
	if (c < ' ' || '~' < c)
		return (0);
	return (1);
}

//  || '~' + 1 <= str[i] is no use due to data type

/*
#include <stdio.h>
#include <unistd.h>

int ft_isprint(char *str);

int main(void){
    char str_a[] = "He/~0";
    char str_b[] = "H\nllö";
    char str_null[] = "";
    int ans_a;
    int ans_b;
    int ans_null;

    write(1, str_a, 5); printf("\n");
    write(1, str_b, 5); printf("\n");
    write(1, str_null, 1); printf("\n");

    ans_a = ft_isprint(str_a);
    ans_b = ft_isprint(str_b);
    ans_null = ft_isprint(str_null);

    printf("%d\n", ans_a);
    printf("%d\n", ans_b);   
    printf("%d\n", ans_null);

    return (0);
};
*/