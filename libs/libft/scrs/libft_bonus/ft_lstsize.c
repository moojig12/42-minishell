/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:17:24 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 21:34:24 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters lst: The beginning of the list.
Return value The length of the list
External functs. None
Description Counts the number of nodes in a list.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	count_size;

	count_size = 0;
	while (lst)
	{
		lst = lst->next;
		count_size++;
	}
	return (count_size);
}
