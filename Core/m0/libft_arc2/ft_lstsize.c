/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veehome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:07:10 by veehome           #+#    #+#             */
/*   Updated: 2024/11/09 16:07:52 by veehome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Calculate the size of the linked list
/// 
/// This function iterates through the linked list `lst`
/// and counts the number of elements,
/// returning the total count as an integer.
/// 
/// @param lst A pointer to the beginning of the list
/// @return The number of elements in the list
int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*temp;

	size = 0;
	temp = lst;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

/*#include <stdio.h>*/
/*#include <stdlib.h>*/
/**/
/*int main(void)*/
/*{*/
/*		t_list node3 = {NULL, NULL};*/
/*		t_list node2 = {NULL, &node3};*/
/*		t_list head = {NULL, &node2};*/
/**/
/*		int size = ft_lstsize(&head);*/
/*		printf("List size: %d\n", size);*/
/*		return 0;*/
/*}*/
/**/
