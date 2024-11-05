#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	idx;

	idx = 0;
	while (src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

int main()
{
    char a[] = "Hello Wor";
    char b[] = "Donkey Kong";

    printf("real: %s\n", ft_strcpy(b, a));
    printf("owns: %s\n", strcpy(b, a));


    return (0);
}