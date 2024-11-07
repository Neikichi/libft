#include "libft.h"
#include <stdlib.h>

/// @brief Create a new list element
/// 
/// This function creates a new linked list element with the given content.
/// The content is duplicated using `ft_strdup` if it is a string, otherwise the pointer is directly assigned.
/// 
/// @param content A pointer to the content for the new list element
/// @return A pointer to the newly created list element, or NULL if allocation fails
t_list *ft_lstnew(void *content)
{
  char *ptr;
  t_list *node;

  ptr = content;
  node = malloc(sizeof(t_list));
  if (!node)
    return (NULL);
  node->content = (void *)ft_strdup(ptr);
  node->next = NULL;
  return (node);
}


#include <stdio.h>  // Library used in main for testing purposes

int main(void)
{
    // Create a new list element with a string
    char str[] = "Hello, world!";
    t_list *node = ft_lstnew(str);

    // Print the content of the new list element
    if (node && node->content)
    {
        printf("Node content: %s\n", (char *)node->content);  // Expected: Hello, world!
    }
    else
    {
        printf("Node creation failed.\n");
    }

    // Free the list element
    if (node)
    {
        free(node->content);
        free(node);
    }

    return 0;
}