/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:22:38 by vlow              #+#    #+#             */
/*   Updated: 2024/11/14 13:41:16 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h" // temporary...
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char *valid_nl(char *buffer, char *load, char *nl_ptr);
static char *load_line(int fd, char *buffer);
static char *set_line(char *buffer, char *load);


char *get_next_line(int fd)
{
	static char *buffer;
	ssize_t size;
	char *valid;

	if (fd < 0 || BUFFER_SIZE == 0 || read(fd, 0, 0))
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
		return (NULL);
	valid = load_line(fd, buffer);
	// size = 1;
	// while (size > 0)
	// {
	// 	size = read(fd, buffer, BUFFER_SIZE);
	// 	if (size == -1)
	// 	{
	// 		free(buffer);
	// 		return (NULL);
	// 	}
	// 	printf("size= %zu | %s\n", size, buffer);
	// }
	return (valid);

}

static char *load_line(int fd, char *buffer)
{
	char *load;
	char *nl_ptr;
	ssize_t size;
	char *valid;

	load = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!load)
	{
		free(buffer);
		return (NULL);
	}
	while (1)
	{
		size = read(fd, load, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			return (NULL);
		}
		nl_ptr = ft_strchr(load, '\n');
		if (nl_ptr && *nl_ptr == '\n')
		{
			valid = valid_nl(buffer, load, nl_ptr);
			buffer = set_line(buffer, nl_ptr + 1);
			return (valid);
		}
		else if (*nl_ptr == '\0')
		{
			return (NULL);
		}
		buffer = set_line(buffer, load);
		

	}
}

static char *valid_nl(char *buffer, char *load, char *nl_ptr)
{
	char *temp;
	char *subs;

	subs = ft_calloc((nl_ptr - load + 2), sizeof(char));
	if (!subs)
	{
		free(buffer);
		free(load);
		return (NULL);
	}
	ft_strlcpy(subs, load, (nl_ptr - load + 1));
	temp = set_line(buffer, subs);
	free(subs);
	return (temp);
}

static char *set_line(char *buffer, char *load)
{
	char *temp;

	temp = ft_calloc(1, sizeof(char));
	if (!temp)
	{
		free(buffer);
		free(load);
		return (NULL);
	}
	temp = ft_strjoin(buffer, load);
	free(buffer);
	return (temp);
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
