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

int ft_strncmp(char *s1, char *s2, unsigned int n)
{  
    unsigned int idx;

    idx = 0;
    if (n == 0)
    {
        return (0);
    }
    while (idx < n && s1[idx] != '\0' && s2[idx] != '\0')
    {
        if (s1[idx] != s2[idx])
            return((s1[idx] - s2[idx]));
        
        idx++;
    }
    if (idx != n)
        return((s1[idx] - s2[idx]));
    return (0);
}

int main(void)
{
    char test[] = "Hello";
    char testt[] = "Hello World";
    printf("%d\n", strncmp(test,testt, 22));
    printf("%d\n", ft_strncmp(test,testt, 22));
}