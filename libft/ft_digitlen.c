/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 06:51:33 by dpatrica          #+#    #+#             */
/*   Updated: 2020/12/01 16:18:20 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digitlen(int num)
{
	int			i;
	long int	long_num;

	long_num = num;
	i = 1;
	if ((long_num < 0) && (++i))
		long_num *= -1;
	while ((long_num > 9) && (++i))
		long_num /= 10;
	return (i);
}
