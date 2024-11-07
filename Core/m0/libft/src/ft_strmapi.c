#include "libft.h"
#include <stdlib.h> // Required for malloc

/// @brief Apply a function to each character of a string to create a new string
/// 
/// This function iterates over each character of the string `s`, applies the
/// function `f` to it (along with the index), and creates a new string with
/// the resulting characters.
/// 
/// @param s The input string
/// @param f The function to apply to each character, taking the index and character as arguments
/// @return A pointer to the newly created string, or `NULL` if allocation fails
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


#include <stdio.h> // For testing purposes

/// @brief Example function to modify each character of a string
/// 
/// This function increments each character by one.
/// 
/// @param i The index of the character (not used in this function)
/// @param c The character to be modified
/// @return The modified character (incremented by one)
char modify_char(unsigned int i, char c)
{
    (void)i; // Unused parameter
    return (c + 1);
}

int main(void)
{
    // Test case: Apply ft_strmapi to modify a string
    const char *str = "abc";
    char *result = ft_strmapi(str, modify_char);
    if (result)
    {
        printf("ft_strmapi result: %s\n", result);  // Expected: "bcd"
        free(result);
    }
    else
    {
        printf("ft_strmapi failed to allocate memory.\n");
    }

    // Test case: Apply ft_strmapi to an empty string
    const char *empty_str = "";
    char *empty_result = ft_strmapi(empty_str, modify_char);
    if (empty_result)
    {
        printf("ft_strmapi result for empty string: '%s'\n", empty_result);  // Expected: ''
        free(empty_result);
    }
    else
    {
        printf("ft_strmapi failed to allocate memory for empty string.\n");
    }

    return 0;
}