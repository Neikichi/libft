#include "libft.h"

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

#include <stdio.h>  // Library used in main for testing purposes

int main(void)
{
    size_t nmemb = 3;
    size_t size = sizeof(int);
    int *arr = ft_calloc(nmemb, size);
    
    if (!arr)
    {
        printf("Memory allocation failed.\n");
        return (1);
    }

    // Test case: Verify all elements are zero-initialized
    for (size_t i = 0; i < nmemb; i++)
    {
        printf("arr[%zu] = %d\n", i, arr[i]);  // Expected: arr[i] = 0 for all i
    }

    free(arr);
    return 0;
}