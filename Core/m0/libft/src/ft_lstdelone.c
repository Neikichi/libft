#include "libft.h"
#include <stdlib.h> // Required for memory management functions

/// @brief Delete a single element of the list
/// 
/// This function deletes and frees the given list element `lst` using the function
/// `del` to free the content. The memory for the list element itself is also freed.
/// 
/// @param lst A pointer to the list element to be deleted
/// @param del A pointer to a function used to delete the content of the element

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
  if (!lst)
    return;
  del(lst->content);
  free(lst);
}

#include <stdio.h>  // Library used in main for testing purposes

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
    // Create a list with a single node
    t_list *node = ft_lstnew(42);

    // Print the content of the node before deleting
    if (node)
    {
        printf("Before deleting: %d\n", *(int *)node->content);
    }

    // Delete the node using ft_lstdelone
    ft_lstdelone(node, ft_del);

    // After deletion, the node should no longer exist (printing would result in undefined behavior)

    return 0;
}