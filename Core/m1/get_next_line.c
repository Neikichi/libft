/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:22:38 by vlow              #+#    #+#             */
/*   Updated: 2024/11/11 21:21:13 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	ssize_t size;

	size = read(fd, buffer, sizeof(buffer));

}

int main(void)
{
	int fd = open("text.txt", O_RDONLY);
	if (!fd)
		return (1);
	while (fd)
		get_next_line(fd);
	

	return (0);
}
