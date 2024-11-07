#include "libft.h"


/// @brief Apply a function to each character of a string with its index
/// 
/// This function iterates over each character of the string `s` and applies the
/// function `f` to it, passing the character's index as the first argument and
/// a pointer to the character as the second argument.
/// 
/// @param s The string to be iterated over
/// @param f The function to apply to each character of the string
void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
  unsigned int i;

  i = 0;
  while (s[i])
  {
    f(i, &s[i]);
    i++;
  }
}


#include <stdio.h>  // For testing purposes

/// @brief Example function to modify each character of a string
/// 
/// This function capitalizes each character in a string passed to it.
/// 
/// @param i The index of the character (not used in this function)
/// @param c A pointer to the character to be modified
void capitalize(unsigned int i, char *c)
{
    if (*c >= 'a' && *c <= 'z')
    {
        *c -= 32;
    }
}

int main(void)
{
    // Test case: Apply ft_striteri to capitalize a string
    char str[] = "hello, world!";
    printf("Original string: %s\n", str);
    ft_striteri(str, capitalize);
    printf("Modified string: %s\n", str);  // Expected: HELLO, WORLD!

    // Test case: Apply ft_striteri to an empty string
    char empty_str[] = "";
    printf("Original empty string: '%s'\n", empty_str);
    ft_striteri(empty_str, capitalize);
    printf("Modified empty string: '%s'\n", empty_str);  // Expected: ''

    return 0;
}