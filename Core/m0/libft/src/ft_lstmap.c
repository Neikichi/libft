#include "libft.h"


/// @brief Create a new list by applying a function to each element of the original list
/// 
/// This function iterates through the list `lst`, applies the function `f` to each element's content,
/// and creates a new list with the resulting elements. If an allocation fails, the `del` function
/// is called to delete the content, and the entire new list is cleared.
/// 
/// @param lst A pointer to the beginning of the list
/// @param f A function to apply to each element's content
/// @param del A function to delete the content in case of an allocation failure
/// @return A pointer to the newly created list, or NULL if an allocation fails
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
  t_list *temp;
  t_list *new;
  t_list *node;

  if (!lst || !f)
    return (NULL);
  temp = lst;
  new = NULL;
  while (temp)
  {
    node = ft_lstnew(f(temp->content));
    if (!node)
    {
      ft_lstclear(&new, del);
      return (NULL);
    }
    ft_lstadd_back(&new, node);
    temp = temp->next;
  }
  return (new);
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


/// @brief Function to double an integer value
/// 
/// This function takes a pointer to an integer and returns a new pointer with double the value.
/// 
/// @param content A pointer to the integer value
/// @return A pointer to the newly allocated doubled value
void *ft_double(void *content)
{
    int *new_value = malloc(sizeof(int));
    if (!new_value)
        return (NULL);
    *new_value = (*(int *)content) * 2;
    return (new_value);
}

/// @brief Delete content of list element
/// 
/// This function deletes the content of a list element.
/// 
/// @param content A pointer to the content to be deleted
void ft_del(void *content)
{
    free(content);
}

#include <stdio.h>  // Library used in main for testing purposes

int main(void)
{
    // Create a list with three nodes
    t_list *head = ft_lstnew(1);
    t_list *node2 = ft_lstnew(2);
    t_list *node3 = ft_lstnew(3);
    head->next = node2;
    node2->next = node3;

    // Map the list to a new list, doubling each value
    t_list *new_list = ft_lstmap(head, ft_double, ft_del);

    // Print the original list
    printf("Original list: ");
    t_list *temp = head;
    while (temp)
    {
        printf("%d -> ", *(int *)temp->content);
        temp = temp->next;
    }
    printf("NULL\n");

    // Print the new list
    printf("Mapped list (doubled values): ");
    temp = new_list;
    while (temp)
    {
        printf("%d -> ", *(int *)temp->content);
        temp = temp->next;
    }
    printf("NULL\n");

    // Free the original list
    ft_lstclear(&head, ft_del);

    // Free the new list
    ft_lstclear(&new_list, ft_del);

    return 0;
}
