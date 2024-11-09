#include "libft.h"
#include <stdio.h>

/// @brief Concatenate strings, taking buffer size into account
/// 
/// This function appends the `src` string to the `dst` string, ensuring that
/// the total length of the resulting `dst` string does not exceed `size` - 1,
/// leaving room for a null terminator. If `size` is smaller or equal to the length
/// of `dst`, `src` will not be appended. The total length of the initial `dst` and
/// `src` strings is returned. If the return value is greater than or equal to `size`,
/// truncation occurred.
/// 
/// @param dst The destination buffer to which `src` will be concatenated
/// @param src The source string to be appended to `dst`
/// @param size The total size of the destination buffer
/// @return The total length of the string it tried to create (initial `dst` length + `src` length)
size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t src_len;
    size_t dest_len;

    i = 0;
    src_len = ft_strlen(src);
    dest_len = ft_strlen(dst);
    if (dest_len >= size)
      return (src_len + size);
    while (src[i] != '\0' && (dest_len + i) < (size - 1))
    {
        dst[dest_len + i] = src[i];
        i++;
    }
    dst[dest_len + i] = '\0';
    return (dest_len + src_len);
}


/*#include <stdio.h>*/
/*#include <string.h>*/
/**/
/*int main(void)*/
/*{*/
/*    char dest1[20] = "Hello, ";*/
/*    const char *src1 = "world!";*/
/*    size_t size1 = sizeof(dest1);*/
/*    size_t result1 = ft_strlcat(dest1, src1, size1);*/
/*    printf("ft_strlcat result: %s\n", dest1);*/
/*    printf("ft_strlcat total length: %zu\n", result1);*/
/**/
/*    return 0;*/
/*}*/
