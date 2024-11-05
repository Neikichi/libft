#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	ft_log(char *str)
{
	while (*str)
	{
		if (!(*str >= 'a' && *str <= 'z') && !(*str >= 'A' && *str <= 'Z'))
		{
			if (!(*str >= '0' && *str <= '9'))
			{
				if (str[1] >= 'a' && str[1] <= 'z')
				{
					str++;
					*str -= 32;
				}
			}
		}
		str++;
		if (*str >= 'A' && *str <= 'Z')
		{
			*str += 32;
		}
	}
}

char	*ft_strcapitalize(char *str)
{
	char	*temp;

	temp = str;
	if (temp[0] >= 'a' && temp[0] <= 'z')
	{
		*str -= 32;
	}
	ft_log(str);
	return (str);
}

int main()
{
    // char a[] = "Hello Wor";
    char b[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

    printf("real: %s\n", ft_strcapitalize(b));
    printf("fake: %s", b);
    // printf("owns: %s\n", strcpy(b, a));


    return (0);
}