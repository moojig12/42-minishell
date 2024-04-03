/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:08:00 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/05 01:42:19 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
libft - not in libc
Parameters
	s: The string to be split.
	c: The delimiter character.
Return value
	The array of new strings resulting from the split.
	NULL if the allocation fails.
External functs. malloc, free
Description
	Allocates (with malloc(3)) and returns an array of strings obtained by
	splitting ’s’ using the character ’c’ as a delimiter. The array must end
	with a NULL pointer.
*/

#include "libft.h"

unsigned int	ft_word_count(char const *s, char c)
{
	unsigned int	words;
	unsigned int	count;

	words = 0;
	count = 0;
	while (s[count] != 0)
	{
		if (count == 0 && s[count] != c)
			words++;
		else if (count != 0 && s[count - 1] == c && s[count] != c)
			words++;
		count++;
	}
	return (words);
}

unsigned int	ft_strlen_c(char const *s, char c)
{
	int	count;

	count = 0;
	while (s[count] != '\0' && s[count] != c)
	{
		count++;
	}
	return (count);
}

char	*ft_word_capture(char const *s, char c, int n)
{
	char			*ptr;
	unsigned int	s_count;
	unsigned int	w_count;

	s_count = 0;
	while (n > 0)
	{
		if (s_count == 0 && s[s_count] != c)
			n--;
		else if (s_count != 0 && s[s_count - 1] == c && s[s_count] != c)
			n--;
		s_count++;
	}
	s_count--;
	ptr = malloc(sizeof(char) * (ft_strlen_c(s + s_count, c) + 1));
	if (!ptr)
		return (0);
	w_count = 0;
	while (s[s_count] != c && s[s_count] != 0)
		ptr[w_count++] = s[s_count++];
	ptr[w_count] = 0;
	return (ptr);
}

static void	*ft_arr_free(char **arr, int i)
{
	while (i >= 0)
	{
		if (arr[i] != NULL)
			free(arr[i]);
		i--;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	words;
	int				count;

	if (s == 0)
		return (0);
	words = ft_word_count(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (0);
	count = 0;
	while (count < (int) words)
	{
		arr[count] = ft_word_capture(s, c, count + 1);
		if (arr[count] == 0)
			return (ft_arr_free(arr, count--));
		count++;
	}
	arr[count] = 0;
	return (arr);
}

// 	i = 0;
// 	count = 0;
// 	count = my_ft_word_count(s, c);
// 	arr = malloc(sizeof(char *) * (count + 1));
// 	if (arr == NULL)
// 		return (NULL);
// 	while (i < count)
// 	{
// 		arr[i] = ft_strsep((char **)&s, &c);
// 		if (arr[i] == NULL)
// 			return (ft_free(arr, i--));
// 		i++;
// 	}
// 	arr[i] = NULL;
// 	return (arr);
// }