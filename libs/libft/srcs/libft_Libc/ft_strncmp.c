/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 01:28:36 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/02 09:37:07 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - Libc function
DESCRIPTION
	The strcmp() function compares the two strings s1 and s2. The locale is not
	taken into account (for a locale-aware comparison, see strcoll(3)). The
	comparison is done using unsigned characters. strcmp() returns an integer
	indicating the result of the comparison, as follows:
	• 0, if the s1 and s2 are equal;
	• a negative value if s1 is less than s2;
	• a positive value if s1 is greater than s2.
	The strncmp() function is similar, except it compares only the first
	(at most) n bytes of s1 and s2.
RETURN VALUE
	The strcmp() and strncmp() functions return an integer less than, equal to,
	or greater than zero if s1 (or the first n bytes thereof) is found,
	respectively, to be less than, to match, or be greater than s2.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 != 0 || *s2 != 0) && n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

/*
#include <stdio.h> //for printf
#include <unistd.h> //for write
#include <stdlib.h> //for atoi

int ft_strncmp(char *s1, char *s2, unsigned int n);

int main(int argc, char *argv[]){

	if (argc == 4){
		printf("%i\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));

	}else if (argc < 2){ //run test cases
		char s1[6] = "HELLO";
		char s2[5] = "HELL";
		char s3[1] = "";

		printf("test str s1:%s\n", s1);
		printf("test str s2:%s\n", s2);
		printf("test str s3:%s(null)\n", s3);
		printf("\n");

		printf("s1,s2,4:%i\n", ft_strncmp(s1, s2, 4));
		printf("s1,s2,5:%i\n", ft_strncmp(s1, s2, 5));
		printf("s1,s3,3:%i\n", ft_strncmp(s1, s3, 3));
		
	}else if (argc < 4){
		printf("%s\n", "too less args!");
	}else if (argc > 4){
		printf("%s\n", "too many args!");
	}
	return (0);
};
*/
