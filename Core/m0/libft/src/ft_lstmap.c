#include "libft.h"

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
