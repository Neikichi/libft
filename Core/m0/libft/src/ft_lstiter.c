#include "libft.h"

/// @brief Iterate through the list and apply a function to each element
/// 
/// This function iterates through the given linked list `lst` and applies the function
/// `f` to the content of each element.
/// 
/// @param lst A pointer to the beginning of the list
/// @param f A pointer to a function used to apply to each element's content
void ft_lstiter(t_list *lst, void (*f)(void *))
{
  if (!lst || !f)
    return;
  t_list *temp;

  temp = lst;
  while (temp)
  {
    f(temp->content);
    temp = temp->next;
  }
}


#include <stdio.h>  // Library used in main for testing purposes
#include <stdlib.h> // Required for malloc and free

/// @brief Print the content of a list element
/// 
/// This function prints the integer content of a list element.
/// 
/// @param content A pointer to the content to be printed
void ft_print(void *content)
{
    printf("%d -> ", *(int *)content);
}

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

    // Apply ft_lstiter to print the content of each node
    printf("List content: ");
    ft_lstiter(head, ft_print);
    printf("NULL\n");

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