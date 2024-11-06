#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
  char *buffer;

  buffer = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
  if (!buffer)
    return (NULL);
  ft_strlcpy(buffer, s1, ft_strlen(s1));
  ft_strlcat(buffer, s2, ft_strlen(s2));
  return (buffer);
} 
