#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/// @brief Allocate and zero-initialize an array
/// 
/// This function allocates memory for an array of `nmemb` elements of `size` bytes each,
/// and initializes all bytes to zero.
/// 
/// @param nmemb Number of elements to allocate
/// @param size Size of each element
/// @return Pointer to allocated memory, or NULL if allocation fails
void *ft_calloc(size_t nmemb, size_t size)
{
    unsigned char *init;
    size_t i;
    
    i = nmemb * size;
    init = malloc(i);
    if (!init)
        return (NULL);
    ft_memset(init, 0, i);
    return init;
}

/*#include <stdio.h>*/
/**/
/*int main(void)*/
/*{*/
/*    size_t nmemb = 3;*/
/*    char *arr = ft_calloc(nmemb, sizeof(char));*/
/**/
/*    if (!arr)*/
/*    {*/
/*        printf("Memory allocation failed.\n");*/
/*        return (1);*/
/*    }*/
/**/
/*    for (size_t i = 0; i < nmemb; i++)*/
/*    {*/
/*        printf("arr[%zu] = %d\n", i, arr[i]); */
/*    }*/
/**/
/*    free(arr);*/
/*    return 0;*/
/*}*/
