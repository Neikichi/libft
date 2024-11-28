/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:03:21 by vlow              #+#    #+#             */
/*   Updated: 2024/09/04 22:11:03 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	idx;
	int	amt;

	idx = 0;
	amt = 1;
	if (nb < 0)
		return (0);
	while (++idx <= nb)
		amt *= idx;
	return (amt);
}
