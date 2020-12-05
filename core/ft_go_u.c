/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:17:32 by dpatrica          #+#    #+#             */
/*   Updated: 2020/12/01 16:17:36 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_map		ft_go_u(t_map param, va_list ap)
{
	unsigned int	s;

	s = va_arg(ap, unsigned int);
	param.type = ft_ungitlen(s);
	s == 0 && param.accuracy == 0 ? param.type = 0 : 0;
	if (param.accuracy <= param.type && param.type < param.width)
		param = ft_unrite(param.flag == 0 || (param.flag == 1 && param.accuracy >= 0) ?\
		3 : param.flag, param.width - param.type, s, param);
	else if (param.type < param.accuracy && param.width <= param.accuracy)
		param = ft_unrite(1, param.accuracy - param.type, s, param);
	else if (param.type >= param.accuracy && param.type >= param.width)
		param = ft_unrite(0, 0, s, param);
	else if (param.type < param.accuracy && param.accuracy < param.width)
	{
		if (param.flag != 2)
			param = ft_unrite(4, param.width - param.accuracy, s, param);
		param = ft_unrite(1, param.accuracy - param.type, s, param);
		if (param.flag == 2)
			param = ft_unrite(4, param.width - param.accuracy, s, param);
	}
	return (param);
}

t_map		ft_unrite(int format, int j, unsigned int s, t_map param)
{
	if ((!format || format == 2) && param.type)
		param.length += ft_unprtnbr(s);
	if (format == 1)
		while (j-- && ++param.length)
			write(1, "0", 1);
	if (format && format != 1)
		while (j-- && ++param.length)
			write(1, " ", 1);
	if (format && format != 2 && format != 4 && param.type)
		param.length += ft_unprtnbr(s);
	return (param);
}

int			ft_unprtnbr(unsigned int n)
{
	char			n_char;

	if (n > 9)
		ft_unprtnbr(n / 10);
	n_char = n % 10 + '0';
	write(1, &n_char, 1);
	return (ft_ungitlen(n));
}
