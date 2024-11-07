#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
  char *buffer;
  unsigned int i;

  i = 0;
  buffer = malloc(sizeof(char) * (ft_strlen(s) + 1));
  if (!buffer)
    return (NULL);
  while (s[i])
  {
    buffer[i] = f(i, s[i]);
    i++;
  }
  buffer[i] = '\0';
  return (buffer);
}
