#include "libft.h"



/// @brief Clear and delete all elements of the list
/// 
/// This function deletes and frees all elements of the linked list pointed to by `lst`,
/// using the function `del` to free the content of each element.
/// After freeing all elements, the list pointer is set to NULL.
/// 
/// @param lst A double pointer to the beginning of the list
/// @param del A pointer to a function used to delete the content of each element
void ft_lstclear(t_list **lst, void(*del)(void *))
{
  t_list *temp;

  if (!lst)
    return;
  while (*lst)
  {
    temp = (*lst)->next;
    ft_lstdelone(*lst, del);
    *lst = temp;
  }
}

#include <stdio.h>  // Library used in main for testing purposes
#include <stdlib.h>

/// @brief Delete content of list element
/// 
/// This function is used to delete the content of a list element.
/// 
/// @param content A pointer to the content to be deleted
void ft_del(void *content)
{
    free(content);
}

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

    // Print the list before clearing
    t_list *temp = head;
    printf("List before clearing: ");
    while (temp)
    {
        printf("%d -> ", *(int *)temp->content);
        temp = temp->next;
    }
    printf("NULL\n");

    // Clear the list
    ft_lstclear(&head, ft_del);

    // Verify that the list has been cleared
    if (head == NULL)
    {
        printf("List after clearing: NULL\n");
    }
    else
    {
        printf("List clearing failed.\n");
    }

    return 0;
}