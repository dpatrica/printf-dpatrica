/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:17:39 by dpatrica          #+#    #+#             */
/*   Updated: 2020/12/01 16:17:41 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_map		ft_go_x(t_map param, va_list ap)
{
	unsigned int	s;

	s = va_arg(ap, unsigned int);
	param.temp = ft_dig16len(s);
	s == 0 && param.accuracy == 0 ? param.temp = 0 : 0;
	if (param.accuracy <= param.temp && param.temp < param.width)
		param = ft_u16ite(param.flag == 0 || (param.flag == 1 && param.accuracy >= 0) ?\
		3 : param.flag,param.width - param.temp, s, param);
	else if (param.temp < param.accuracy && param.width <= param.accuracy)
		param = ft_u16ite(1, param.accuracy - param.temp, s, param);
	else if (param.temp >= param.accuracy && param.temp >= param.width)
		param = ft_u16ite(0, 0, s, param);
	else if (param.temp < param.accuracy && param.accuracy < param.width)
	{
		if (param.flag != 2)
			param = ft_u16ite(4, param.width - param.accuracy, s, param);
		param = ft_u16ite(1, param.accuracy - param.temp, s, param);
		if (param.flag == 2)
			param = ft_u16ite(4, param.width - param.accuracy, s, param);
	}
	return (param);
}

t_map		ft_u16ite(int format, int j, unsigned int str, t_map param)
{
	if ((!format || format == 2) && param.temp)
		param.length += ft_put16(str, param.type);
	if (format == 1)
		while (j-- && ++param.length)
			write(1, "0", 1);
	if (format && format != 1)
		while (j-- && ++param.length)
			write(1, " ", 1);
	if (format && format != 2 && format != 4 && param.temp)
		param.length += ft_put16(str, param.type);
	return (param);
}

int			ft_put16(unsigned int n, int type)
{
	int		x;
	char	n_char;

	x = type;
	x = x == 'x' ? 22 : -10;
	if (n > 15)
		ft_put16(n / 16, type);
	n_char = (n % 16) < 10 ? (n % 16) + '0' : (n % 16) + 'A' + x;
	write(1, &n_char, 1);
	return (ft_dig16len(n));
}
