/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:17:45 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 23:35:29 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters 
	content: The content to create the node with.
Return value 
	The new node
External functs. malloc
Description
	Allocates (with malloc(3)) and returns a new node. The member variable
	’content’ is initialized with the value of the parameter ’content’.
	The variable ’next’ is initialized to NULL
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *) malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
