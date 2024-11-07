#include "libft.h"
#include <stdlib.h>  // Required for malloc

/// @brief Concatenate two strings into a new dynamically allocated string
/// 
/// This function concatenates the strings `s1` and `s2` into a new string.
/// The memory for the new string is allocated using `malloc` and should be
/// freed by the caller.
/// 
/// @param s1 The first string
/// @param s2 The second string
/// @return A pointer to the newly allocated string, or `NULL` if allocation fails
char *ft_strjoin(char const *s1, char const *s2)
{
  char *buffer;

  buffer = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
  if (!buffer)
    return (NULL);
  ft_strlcpy(buffer, s1, ft_strlen(s1));
  ft_strlcat(buffer, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
  return (buffer);
} 


#include <stdio.h>  // For testing purposes

int main(void)
{
    // Test case 1: Basic concatenation
    const char *s1 = "Hello, ";
    const char *s2 = "world!";
    char *result = ft_strjoin(s1, s2);
    if (result)
    {
        printf("ft_strjoin result: %s\n", result);  // Expected: Hello, world!
        free(result);
    }
    else
    {
        printf("ft_strjoin failed to allocate memory.\n");
    }

    // Test case 2: Empty strings
    char *empty_result = ft_strjoin("", "");
    if (empty_result)
    {
        printf("ft_strjoin result for empty strings: '%s'\n", empty_result);  // Expected: ''
        free(empty_result);
    }
    else
    {
        printf("ft_strjoin failed to allocate memory for empty strings.\n");
    }

    // Test case 3: One empty string and one non-empty string
    char *one_empty_result = ft_strjoin("Hello", "");
    if (one_empty_result)
    {
        printf("ft_strjoin result for one empty string: '%s'\n", one_empty_result);  // Expected: 'Hello'
        free(one_empty_result);
    }

    return 0;
}