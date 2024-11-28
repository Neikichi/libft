/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:45:29 by vlow              #+#    #+#             */
/*   Updated: 2024/09/05 19:50:57 by vlow             ###   ########.fr       */
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
	if (argc > 0)
	{
		write(1, argv[0], ft_strlen(argv[0]));
		write(1, "\n", 1);
	}
	return (0);
}
