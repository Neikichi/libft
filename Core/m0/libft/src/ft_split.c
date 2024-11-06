#include "libft.h"

static char **ft_split_ex(char const *s, char c, char **result);
static int ft_countword(char *str, char *charset);

char  **ft_split(char const *s, char c)
{
  char **result;
  int size;

  if (*s == '\0')
  {
    result = malloc(sizeof(char *) * 1 + 1);
    if (!result)
      return (NULL);
    result[0] = NULL;
    return (result);
  }
  size = ft_countword(s, c);
  result = malloc(sizeof(char *) * (size + 1));
  if (!result)
    return (NULL);
  return (ft_split_ex(s, c, result));
}

static char **ft_split_ex(char const *s, char c, char **result)
{
  int i;
  const char *ptr;

  i = 0;
  while (*s)
  {
    while (*s && ft_strchr(c, *s))
      s++;
    if (*s)
    {
      ptr = s;
      while (*ptr && !ft_strchr(c, *s))
        ptr++;
      result = malloc(sizeof(char) * (ptr - s + 1):while (true) {
      });
      if (!result)
        return (NULL);
      ft_strlcpy(result[i], s, (ptr - s));
      i++;
      s = ptr;
    }
  }
  result[i] = NULL;
  return (result);
}

static int ft_countword(char *str, char *charset)
{
  int cnt;
  int flag;
  int set;

  cnt = 0;
  flag = 0;
  while (*str)
  {
    set = 0;
    if(ft_strchr(charset, *str))
      set = 1;
    if (set == 0 && flag == 0)
    {
      cnt++;
      flag = 1;
    }
    if (set == 1)
      flag = 0;
    str++;
  }
  return (cnt);
}
