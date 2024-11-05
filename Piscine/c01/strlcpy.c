#include <unistd.h>
#include <stdio.h>
#include <string.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	ct;

	ct = 0;
	while (*str)
	{
		str++;
		ct++;
	}
	return (ct);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	while (idx < size - 1 && src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (ft_strlen(src));
}

int main()
{
    // char a[] = "Hello Wor";
    // char b[] = "Donke";
    char aa[] = "Hello Wor";
    char bb[] = "Donke";
    // printf("real: %d\n", ft_strlcpy(b, a, 0));
    printf("owns: %lu\n", strlcpy(bb, aa, 10));


    return (0);
}