#include "libft.h"
#include <stdlib.h>  // Required for malloc

/// @brief Trim characters from the beginning and end of a string
/// 
/// This function removes all characters in `set` from both the beginning and
/// the end of the string `s1`. The trimmed string is returned as a new dynamically
/// allocated string.
/// 
/// @param s1 The input string to be trimmed
/// @param set The set of characters to be removed from `s1`
/// @return A pointer to the newly trimmed string, or `NULL` if allocation fails
char *ft_strtrim(char const *s1, char const *set)
{
  const char *start;
  char *buffer;
  const char *end;

  start = s1;
  while (*start && ft_strchr(set, *start))
  { 
    start++;
  }
  end = s1 + ft_strlen(s1) - 1;
  while (ft_strchr(set, *end) && end >= start)
  {
    end--;
  }
  buffer = malloc(sizeof(char) * (end - start + 1));
  if (!buffer)
    return (NULL);
  ft_strlcpy(buffer, start, (end - start + 1));
  return (buffer);
}


#include <stdio.h>  // For testing purposes

int main(void)
{
    // Test case 1: Normal trim with characters at both ends
    const char *s1 = "+++Hello, world!+++";
    const char *set = "+";
    char *result = ft_strtrim(s1, set);
    if (result)
    {
        printf("ft_strtrim result: '%s'\n", result);  // Expected: "Hello, world!"
        free(result);
    }

    // Test case 2: Trim with no characters to remove
    const char *s2 = "Hello, world!";
    const char *set2 = "+";
    result = ft_strtrim(s2, set2);
    if (result)
    {
        printf("ft_strtrim result: '%s'\n", result);  // Expected: "Hello, world!"
        free(result);
    }

    // Test case 3: Trim all characters
    const char *s3 = "+++++";
    const char *set3 = "+";
    result = ft_strtrim(s3, set3);
    if (result)
    {
        printf("ft_strtrim result: '%s'\n", result);  // Expected: ""
        free(result);
    }

    // Test case 4: Empty input string
    const char *s4 = "";
    const char *set4 = "+";
    result = ft_strtrim(s4, set4);
    if (result)
    {
        printf("ft_strtrim result: '%s'\n", result);  // Expected: ""
        free(result);
    }

    return 0;
}