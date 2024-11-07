#include "libft.h"

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
