#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max)
{
    int *range;
    int dif;
    int idx;

    if (min >= max)
        return (NULL);
    dif = max - min;
    range = malloc(dif * sizeof(int));
    if (!range)
        return (NULL);
    idx = 0;
    range[0] = min;
    while (++idx < dif)
        range[idx] = ++min;
    return (range);   
}

int main(void)
{
    int min = 1;
    int max = 1000000;
    int *range = ft_range(min, max);
    
    if (range == NULL)
    {
        printf("Null pointer returned\n");
        return (1);
    }

    for (int i = 0; i < max - min; i++)
    {
        printf("%d ", range[i]);
    }
    printf("\n");
    free(range);

    return (0);
}