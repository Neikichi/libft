/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:56:16 by vlow              #+#    #+#             */
/*   Updated: 2024/11/18 12:03:30 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char	*valid_nl(char **buffer, char *load, char *nl_ptr);
static char	*load_line(int fd, char **buffer);
static char	*set_line(char **buffer, char *load, ssize_t size);
static int	nl_check(char **buffer, char **load, ssize_t size);

char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		size;
	char		*valid;

	if (fd < 0 || BUFFER_SIZE == 0 || read(fd, 0, 0))
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	valid = load_line(fd, &buffer);
	if (!valid)
	{
		free(buffer);
		return (NULL);
	}
	return (valid);
}

static char	*load_line(int fd, char **buffer)
{
	char	*load;
	char	*nl_ptr;
	ssize_t	size;

	load = malloc(BUFFER_SIZE + 1);
	if (!load)
		return (NULL);
	while (1)
	{
		size = read(fd, load, BUFFER_SIZE);
		load[size] = '\0';
		if (size == -1)
		{
			free(load);
			return (NULL);
		}
		if (size == 0)
		{
			load = set_line(buffer, load, size);
			return (load);
		}
		if (nl_check(buffer, &load, size))
			return (load);
		*buffer = set_line(buffer, load, 1);
	}
}

static int	nl_check(char **buffer, char **load, ssize_t size)
{
	char	*nl_ptr;
	char	*l_ptr;

	nl_ptr = *load;
	while (*nl_ptr)
	{
		if (*nl_ptr == '\n')
			break ;
		nl_ptr++;
	}
	if (*nl_ptr == '\n')
	{
		*load = valid_nl(buffer, *load, nl_ptr);
		return (1);
	}
	return (0);
}

static char	*valid_nl(char **buffer, char *load, char *nl_ptr)
{
	char	*temp;
	char	*subs;

	subs = malloc((nl_ptr - load) + 2);
	if (!subs)
		return (NULL);
	ft_strlcpy(subs, load, (nl_ptr - load) + 2);
	temp = set_line(buffer, subs, 1);
	free(subs);
	*buffer = ft_strdup(nl_ptr + 1);
	free(load);
	return (temp);
}

static char	*set_line(char **buffer, char *load, ssize_t size)
{
	char	*temp;

	if (size == 0)
	{
		if (!(*buffer) || (*buffer)[0] == '\0')
		{
			free(load);
			return (NULL);
		}
		free(load);
		temp = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
		return (temp);
	}
	temp = ft_strjoin(*buffer, load);
	free(*buffer);
	return (temp);
}
//
// int main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
//
//     char *line;
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
// 		free(line);
//     }
// 	printf("%s", line);
// 	free(line);
//
//     close(fd);
// 	return (0);
// }
