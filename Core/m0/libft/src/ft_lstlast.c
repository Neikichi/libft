#include "libft.h"

/// @brief Get the last element of the list
/// 
/// This function returns the last element of the linked list `lst`.
/// If the list is empty (i.e., `lst` is NULL), the function returns NULL.
/// 
/// @param lst A pointer to the beginning of the list
/// @return A pointer to the last element of the list, or NULL if the list is empty
t_list *ft_lstlast(t_list *lst)
{
  if (!lst)
    return (NULL);
  while (lst->next)
  {
    lst = lst->next;
  }
  return (lst);
}


#include <stdio.h>  // Library used in main for testing purposes
#include <stdlib.h> // Required for malloc and free

/// @brief Create a new list element
/// 
/// This function creates a new linked list element with the given value.
/// 
/// @param value The integer value for the new list element
/// @return A pointer to the newly created list element
t_list *ft_lstnew(int value)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    int *content = malloc(sizeof(int));
    if (!content)
    {
        free(node);
        return (NULL);
    }
    *content = value;
    node->content = content;
    node->next = NULL;
    return (node);
}

int main(void)
{
    // Create a list with three nodes
    t_list *head = ft_lstnew(1);
    t_list *node2 = ft_lstnew(2);
    t_list *node3 = ft_lstnew(3);
    head->next = node2;
    node2->next = node3;

    // Get the last element of the list
    t_list *last = ft_lstlast(head);
    if (last)
    {
        printf("Last element content: %d\n", *(int *)last->content);  // Expected: 3
    }
    else
    {
        printf("The list is empty.\n");
    }

    // Free the list
    t_list *temp = head;
    while (temp)
    {
        t_list *next = temp->next;
        free(temp->content);
        free(temp);
        temp = next;
    }

    return 0;
}