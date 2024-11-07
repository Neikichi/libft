#include "libft.h"
#include <stdlib.h> // For malloc

static char **ft_split_ex(char const *s, char c, char **result);
static int ft_countword(const char *str, char *charset);

/// @brief Split a string into words based on a given delimiter
/// 
/// This function splits the given string `s` into an array of strings using the character `c` as a delimiter.
/// The resulting array of strings is null-terminated.
/// 
/// @param s The string to be split
/// @param c The character used as a delimiter
/// @return A pointer to an array of strings, or `NULL` if allocation fails
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
  size = ft_countword(s, &c);
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
    while (*s && ft_strchr(&c, *s))
      s++;
    if (*s)
    {
      ptr = s;
      while (*ptr && !ft_strchr(&c, *s))
        ptr++;
      result = malloc(sizeof(char) * (ptr - s + 1));
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

static int ft_countword(const char *str, char *charset)
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


#include <stdio.h> // For testing purposes

int main(void)
{
    // Test case 1: Basic usage
    char **result = ft_split("Hello,world,this,is,a,test", ',');
    if (result)
    {
        for (int i = 0; result[i] != NULL; i++)
        {
            printf("Word %d: %s\n", i, result[i]);
            free(result[i]);
        }
        free(result);
    }

    // Test case 2: Delimiter at the start and end
    result = ft_split(",start,middle,end,", ',');
    if (result)
    {
        for (int i = 0; result[i] != NULL; i++)
        {
            printf("Word %d: %s\n", i, result[i]);
            free(result[i]);
        }
        free(result);
    }

    // Test case 3: Empty string
    result = ft_split("", ',');
    if (result)
    {
        if (result[0] == NULL)
            printf("Empty string result: NULL\n");
        free(result);
    }

    return 0;
}