#include <stdlib.h>
#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max)
{
    if (min >= max)
    {
        *range = NULL;
        return (0);
    }
    int dif;
    int idx;

    dif = max - min;
    *range = malloc(dif * sizeof(int));
    if (!*range)
    {
        *range = NULL;
        return (-1);
    }
    idx = 0;
    (*range)[0] = min;
    while (++idx < dif)
        (*range)[idx] = ++min;
    return (dif);  
}

int main(void)
{
    int *range;
    int size = ft_ultimate_range(&range, 0, 100000);

    if (size == -1)
        printf("Memory allocation failed\n");
    else
    {
        printf("Size: %d\n", size);  // Expected output: Size: 100000
        // Optionally, print the first few values
        for (int i = 0; i < 10; i++)
            printf("%d ", range[i]);  // Expected output: 0 1 2 3 4 5 6 7 8 9
        printf("\n");
    }

    // Free the allocated memory after usage
    if (range != NULL)
        free(range);

    return 0;
}




