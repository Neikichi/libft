#include "libft.h"
#include <stdio.h>

/// @brief Copy a string to a destination buffer, considering buffer size
/// 
/// This function copies up to `size - 1` characters from the string `src` to `dst`,
/// null-terminating the result if `size` is not zero.
/// 
/// @param dst The destination buffer to which the string is copied
/// @param src The source string to be copied
/// @param size The total size of the destination buffer
/// @return The total length of the source string (`src`)
size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;

    i = 0;
    if (size > 0)
    {
        while (i < size - 1 && src[i] != '\0')
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return (ft_strlen(src));
}

/*#include <stdio.h>*/
/**/
/*int main(void)*/
/*{*/
/*    const char *src1 = "Hello, world!";*/
/*    char dest1[20];*/
/*    size_t result1 = ft_strlcpy(dest1, src1, sizeof(dest1));*/
/*    printf("result: %s\n", dest1);*/
/*    printf("total length: %zu\n", result1);*/
/**/
/*    return 0;*/
/*}*/
