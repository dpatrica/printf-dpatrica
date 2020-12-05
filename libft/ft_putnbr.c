/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 06:51:33 by dpatrica          #+#    #+#             */
/*   Updated: 2020/11/08 13:41:49 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char		n_char;
	long int	n_long;

	n_long = n;
	if (n_long < 0)
	{
		write(1, "-", 1);
		n_long *= -1;
	}
	if (n_long > 9)
		ft_putnbr(n_long / 10);
	n_char = n_long % 10 + '0';
	write(1, &n_char, 1);
}
