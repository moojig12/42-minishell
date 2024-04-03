/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:17:34 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 21:46:24 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters
	lst: The node to free.
	del: The address of the function used to delete the content.
Return value None
External functs. free
Description
	Takes as a parameter a node and frees the memory of the node’s content using
	the function ’del’ given as a parameter and free the node. The memory of
	’next’ must not be freed.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del)
		return ;
	if (!lst)
		return ;
	(*del)(lst -> content);
	free(lst);
	return ;
}
