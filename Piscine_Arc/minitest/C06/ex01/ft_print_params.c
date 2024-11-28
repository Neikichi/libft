/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:51:59 by vlow              #+#    #+#             */
/*   Updated: 2024/09/05 19:54:01 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

int	main(int argc, char *argv[])
{
	int	idx;

	idx = 1;
	if (argc > 1)
	{
		while (idx < argc)
		{
			write(1, argv[idx], ft_strlen(argv[idx]));
			write(1, "\n", 1);
			idx++;
		}
	}
	return (0);
}
