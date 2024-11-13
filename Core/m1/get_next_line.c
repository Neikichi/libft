/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:22:38 by vlow              #+#    #+#             */
/*   Updated: 2024/11/13 14:19:52 by vlow             ###   ########.fr       */
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
	static char *buffer;
	ssize_t size;

	if (fd < 0 || BUFFER_SIZE == 0 || read(fd, 0, 0))
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	size = 1;
	while (size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			return (NULL);
		}
		printf("size= %zu | %s\n", size, buffer);
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
