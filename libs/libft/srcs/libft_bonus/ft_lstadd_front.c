/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:17:30 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 21:46:38 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters
	lst: The address of a pointer to the first link of a list.
	new: The address of a pointer to the node to be added to the list.
Return value None
External functs. None
Description Adds the node ’new’ at the beginning of the list.
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (*lst)
		new -> next = *lst;
	*lst = new;
	return ;
}
