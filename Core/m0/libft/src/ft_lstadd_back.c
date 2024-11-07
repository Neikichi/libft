#include "libft.h"

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
