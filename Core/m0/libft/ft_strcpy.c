#include "libft.h"


/// @brief Copy a string to a destination buffer
/// 
/// This function copies the string `src` (including the terminating null byte)
/// to the buffer `dest`. The destination buffer must be large enough to receive
/// the entire string.
/// 
/// @param dest The destination buffer where the string is copied to
/// @param src The source string to be copied
/// @return A pointer to the destination buffer (`dest`)
char *ft_strcpy(char *dest, const char *src)
{
    char *ptr;

    ptr = dest;
    while (*src)
    {
        *ptr = *src;
        src++;
        ptr++;
    }
    *ptr = '\0';
    return (dest);
}

/*#include <stdio.h>*/
/*#include <string.h>*/
/**/
/*int main(void)*/
/*{*/
/*    char src[] = "Hello, world!";*/
/*    char dest[20];*/
/**/
/*    char *result = ft_strcpy(dest, src);*/
/*    printf("ft_strcpy result: %s\n", result);*/
/**/
/*    char std_dest[20];*/
/*    char *stdres = strcpy(std_dest, src);*/
/*    printf("Standard strcpy result: %s\n", stdres);*/
/**/
/*    return 0;*/
/*}*/
