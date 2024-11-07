#include "libft.h"
#include <stdlib.h>

/// @brief Duplicate a string
/// 
/// This function allocates sufficient memory for a copy of the string `s`,
/// copies the string, and returns a pointer to it. The memory for the new
/// string is obtained with `malloc` and should be freed by the caller.
/// 
/// @param s The source string to be duplicated
/// @return A pointer to the duplicated string, or `NULL` if memory allocation fails
char *ft_strdup(const char *s)
{
    char *dup;

    if (!s)
        return (NULL);
    dup = malloc(ft_strlen(s) + 1);
    if (!dup)
        return (NULL);
    ft_strcpy(dup, s);
    return (dup);
}


#include <stdio.h>  // For testing purposes
#include <string.h> // For comparison with standard strdup

int main(void)
{
    // Test case: Duplicate a string
    const char *src = "Hello, world!";
    char *dup = ft_strdup(src);

    if (dup)
    {
        printf("ft_strdup result: %s\n", dup);  // Expected: Hello, world!
        free(dup);
    }
    else
    {
        printf("ft_strdup failed to allocate memory.\n");
    }

    // Test case: Duplicate an empty string
    const char *empty_src = "";
    char *empty_dup = ft_strdup(empty_src);

    if (empty_dup)
    {
        printf("ft_strdup result for empty string: '%s'\n", empty_dup);  // Expected: ''
        free(empty_dup);
    }
    else
    {
        printf("ft_strdup failed to allocate memory for empty string.\n");
    }

    // Test case: Compare with standard strdup
    char *std_dup = strdup(src);
    if (std_dup)
    {
        printf("Standard strdup result: %s\n", std_dup);  // Expected: Hello, world!
        free(std_dup);
    }

    return 0;
}