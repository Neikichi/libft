#include "libft.h"

/// @brief Add new element at the end of the list
/// 
/// This function adds a new element `new` at the end of the linked list pointed to by `lst`.
/// If the list is empty, the new element becomes the first element.
/// 
/// @param lst A double pointer to the beginning of the list
/// @param new A pointer to the new element to be added
void ft_lstadd_back(t_list **lst, t_list *new)
{
  if (!lst || !new)
    return;
  t_list *temp;

  temp = *lst;
  while (temp->next)
  {
    temp = temp->next;
  }
  temp->next = new;
}


#include <stdio.h>  // Library used in main for testing purposes
#include <stdlib.h> // Required for malloc and free
int main(void)
{
    // Create a list with initial node
    t_list *head = ft_lstnew(1);
    t_list *node2 = ft_lstnew(2);
    t_list *node3 = ft_lstnew(3);

    // Add nodes to the list
    ft_lstadd_back(&head, node2);
    ft_lstadd_back(&head, node3);

    // Traverse the list and print the content
    t_list *temp = head;
    while (temp)
    {
        printf("%d -> ", temp->content);
        temp = temp->next;
    }
    printf("NULL\n");

    // Free the list
    temp = head;
    while (temp)
    {
        t_list *next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}