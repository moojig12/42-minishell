/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 02:58:55 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/16 23:35:34 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - Libc function
DESCRIPTION
	The atoi() function converts the initial portion of the string pointed to by
	nptr to int. The behavior is the same as
		strtol(nptr, NULL, 10);
	except that atoi() does not detect errors.
RETURN VALUE
	The converted value or 0 on error.
*/

int	ft_atoi(const char *nptr)
{
	int	count;
	int	number;
	int	sign;

	count = 0;
	sign = 1;
	while (nptr[count] == ' ' || (9 <= nptr[count] && nptr[count] <= 13))
		count++;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			sign *= -1;
		count++;
	}
	number = 0;
	while ('0' <= nptr[count] && nptr[count] <= '9')
	{
		number = (number * 10) + ((nptr[count] - '0'));
		count++;
	}
	return (sign * number);
}

/*
#include <stdio.h> //for printf
// #include <unistd.h> //for write
#include <stdlib.h> //for atoi

int ft_atoi(char *nptr);

int main(int argc, char *argv[]){

    if (argc == 2){
        ft_atoi(argv[1]);

    }else if (argc < 2){ //run test cases
        char *nptr;
        nptr = "      ---+--+1234ab567";
        printf("%i\n", ft_atoi(nptr));
        `
    }else if (argc < 2){
        printf("%s\n", "too less args!");
    }else if (argc > 2){
        printf("%s\n", "too many args!");
    }
    return (0);
};
*/
