#include "libft.h"

/// @brief Locate a substring in a string, up to a maximum length
/// 
/// This function locates the first occurrence of the null-terminated substring `little`
/// in the string `big`, where no more than `len` characters are searched.
/// 
/// @param big The larger string to be searched
/// @param little The substring to be located in `big`
/// @param len The maximum number of characters to search
/// @return A pointer to the beginning of the located substring, or `NULL` if not found
char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;

    i = 0;
    if (!*little)
        return ((char *)big);
    while (big[i] && i < len)
    {
        j = 0;
        if (little[j] == big[i])
        {
            while (little[j] && big[i + j] && (i + j) < len)
            {
                if (big[i + j] != little[j])
                    break;
                j++;
            }
            if (!little[j])
                return ((char *)big + i);
        }
        i++;
    }
    return (NULL);
}

#include <stdio.h> // For testing purposes
#include <string.h> // For comparison with standard strnstr

int main(void)
{
    // Test case 1: Normal substring match within len
    const char *big1 = "Hello, world!";
    const char *little1 = "world";
    size_t len1 = 13;
    char *result1 = ft_strnstr(big1, little1, len1);
    printf("ft_strnstr result: %s\n", result1 ? result1 : "NULL");  // Expected: world!

    // Test case 2: No match found
    const char *big2 = "Hello, world!";
    const char *little2 = "planet";
    size_t len2 = 13;
    char *result2 = ft_strnstr(big2, little2, len2);
    printf("ft_strnstr result: %s\n", result2 ? result2 : "NULL");  // Expected: NULL

    // Test case 3: Match exists but outside the given len
    const char *big3 = "Hello, world!";
    const char *little3 = "world";
    size_t len3 = 5; // Searching only within the first 5 characters
    char *result3 = ft_strnstr(big3, little3, len3);
    printf("ft_strnstr result: %s\n", result3 ? result3 : "NULL");  // Expected: NULL

    // Test case 4: Empty little string
    const char *big4 = "Hello, world!";
    const char *little4 = "";
    size_t len4 = 13;
    char *result4 = ft_strnstr(big4, little4, len4);
    printf("ft_strnstr result: %s\n", result4 ? result4 : "NULL");  // Expected: Hello, world!

    // Test case 5: Compare with standard strnstr
    const char *big5 = "Hello, world!";
    const char *little5 = "world";
    size_t len5 = 13;
    char *std_result = strnstr(big5, little5, len5);
    printf("Standard strnstr result: %s\n", std_result ? std_result : "NULL");  // Expected: world!

    return 0;
}