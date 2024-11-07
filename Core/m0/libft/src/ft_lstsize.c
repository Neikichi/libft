#include "libft.h"


/// @brief Calculate the size of the linked list
/// 
/// This function iterates through the linked list `lst` and counts the number of elements,
/// returning the total count as an integer.
/// 
/// @param lst A pointer to the beginning of the list
/// @return The number of elements in the list
int ft_lstsize(t_list *lst)
{
  int size;
  t_list *temp;

  size = 0;
  temp = lst;
  while (temp)
  {
    size++;
    temp = temp->next;
  }
  return (size);
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

    // Calculate and print the size of the list
    int size = ft_lstsize(head);
    printf("List size: %d\n", size);  // Expected: 3

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