/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_c_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:17:11 by dpatrica          #+#    #+#             */
/*   Updated: 2020/12/01 16:17:14 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_map	ft_go_c_percent(t_map p, va_list ap)
{
	char	s;

	s = p.type == 'c' ? va_arg(ap, int) : '%';
	if (p.width && (!p.flag || p.flag == 1))
	{
		if (!p.flag)
			while (--p.width && ++p.length)
				write(1, " ", 1);
		else if (p.flag == 1)
			while (--p.width && ++p.length)
				write(1, "0", 1);
	}
	write(1, &s, 1);
	p.length++;
	if (p.width && p.flag == 2)
		while (--p.width && ++p.length)
			write(1, " ", 1);
	return (p);
}
