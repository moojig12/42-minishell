/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:17:59 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/02 09:37:43 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - Libc function
DESCRIPTION
    The strlen() function calculates the length of the string pointed to by s,
    excluding the terminating null byte ('\0').
RETURN VALUE
    The strlen() function returns the number of bytes in the string pointed to
    by s.
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

/*
#include <stdio.h> //for printf
// #include <unistd.h> //for write

int ft_strlen(char *str);

int main(int argc, char *argv[]){
    char *str;
    int n;

    if (argc == 2){
        n = ft_strlen(argv[1]);
        printf("%i\n", n);
        
    }else if (argc < 2){ //run test cases

        n = 0;
        printf("%d\n", n);

        str = "this is string";    
        n = ft_strlen(str);
        printf("String Length is %d\n", n);
        
    }else if (argc < 3){
        printf("%s\n", "too less args!");
    }else if (argc > 3){
        printf("%s\n", "too many args!");
    }
    return (0);
};
*/
