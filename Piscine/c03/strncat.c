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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*temp;
	unsigned int	idx;

	temp = dest;
	idx = 0;
	while (*temp != '\0')
	{
		temp++;
	}
	while (*src != '\0' && idx < nb)
	{
		*temp++ = *src++;
		idx++;
	}
	*temp = '\0';
	return (dest);
}

int main(void)
{
    char src[] = "Hello";
    char dest[5] = "World";
    char src1[] = "Hello";
    char dest1[5] = "World";
    // printf("%s\n", strncat(dest, src, 10));
    printf("%s\n", ft_strncat(dest1, src1,10));
}