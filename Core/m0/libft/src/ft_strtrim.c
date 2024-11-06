#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
  const char *start;
  char *buffer;
  const char *end;

  start = s1;
  while (*start && strchr(set, *start))
  { 
    start++;
  }
  end = s1 + ft_strlen(s1) - 1;
  while (strchr(set, *end) && end >= start)
  {
    end--;
  }
  buffer = malloc(sizeof(char) * (end - start + 1));
  if (!buffer)
    return (NULL);
  ft_strlcpy(buffer, start, (end - start + 1));
  return (buffer);
}
