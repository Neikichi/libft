#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	ct;

	ct = 0;
	while (*str)
	{
		str++;
		ct++;
	}
	return (ct);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while (idx < n && src[idx] != '\0')
	{
        dest[idx] = src[idx];
        idx++;
	}
    while (idx < n)
    {
        dest[idx] = '\0';
		idx++;
    }
	return (dest);
}

int main()
{
    // char a[] = "Hello Wor";
    // char b[] = "Donke";
    char aa[] = "Hello Wor";
    char bb[] = "Donke";
    // printf("real: %s\n", ft_strncpy(b, a, 10));
    printf("owns: %s\n", strncpy(bb, aa, 10));


    return (0);
}