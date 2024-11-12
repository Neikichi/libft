#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;

	if (!s1)
	{
		buffer = malloc(ft_stlen(s2));
		ft_strlcpy(buffer, s1, ft_strlen(s1) + 1);
	}
	else
	{
		buffer = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!buffer)
			return (NULL);
		ft_strlcat(buffer, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
		free(s1);
	}
	return (buffer);
}


int main(void)
{
	
	ft_putnbr_fd(-2147483649, 1);


	// char *str;
	// printf("=a=a=a=\n");
	//
	// str = ft_calloc((size_t)-1, 1);
	// if (!str)
	// {
	// 	printf("inside null");
	// 	return 1;
	// }
	// // str = ft_calloc(0, 0);
	//
	// printf("==%zu\n",(size_t)-1 * 5);
	
	return 0;
}
