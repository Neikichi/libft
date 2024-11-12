/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:22:38 by vlow              #+#    #+#             */
/*   Updated: 2024/11/12 17:34:24 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h" // temporary...
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	ssize_t size;
	char *ptr1 = buffer;
	char *ptr2 = buffer;

	size = read(fd, buffer, sizeof(buffer));
	if (size <= 0)
	{
		buffer[size] = '\0';
		return (NULL);
	}
	while (*ptr1)
	{
		if (*ptr1 == '\n')
		{
			// printf("%.*s", (int)(ptr1 - ptr2 + 1), ptr1);
			char *fline = ft_substr(buffer, (ptr2 - buffer), (ptr1 - ptr2 + 1));
			if (!fline)
			{
				printf("fline failed.\n");
				return (NULL);
			}
			printf("fline = \'%s\'", fline);
			free(fline);
			ptr2 = ptr1 + 1;
		}
		// else
		// {
		// 	get_next_line(fd);
		// }
		ptr1++;
	}
	return (buffer);

}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);

    // char *line;
    // while ((line = get_next_line(fd)) != NULL)
    // {
    //     printf("%s", line);  // Print each line read
    // }
	
	get_next_line(fd);

    close(fd);  // Close the file descriptor

	

	return (0);
}
