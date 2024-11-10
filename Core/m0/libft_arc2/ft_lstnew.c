/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veehome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:05:02 by veehome           #+#    #+#             */
/*   Updated: 2024/11/09 16:06:53 by veehome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/// @brief Create a new list element
/// 
/// Function creates a new linked list element with the given content.
/// The content is directly assigned to the new list element 
/// and is not duplicated.
/// Therefore, the caller is responsible for managing the 
/// memory of the content, 
/// including freeing it if it was dynamically allocated.
/// 
/// @param content A pointer to the content for the new list element
/// @return A pointer to the newly created list element,or
///			NULL if allocation fails
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*#include <stdio.h>*/
/*int main(void)*/
/*{*/
/*		char str[] = "Hello, world!";*/
/*		t_list *node = ft_lstnew(str);*/
/**/
/*		printf("Node content: %s\n", (char *)node->content);*/
/**/
/*		free(node);*/
/**/
/*		return 0;*/
/*}*/
