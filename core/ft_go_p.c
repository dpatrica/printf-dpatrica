/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:17:22 by dpatrica          #+#    #+#             */
/*   Updated: 2020/12/01 16:17:23 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_map		ft_go_p(t_map param, va_list ap)
{
	unsigned long	s;

	s = va_arg(ap, unsigned long);
	param.temp = ft_digplen(s) + (param.accuracy > ft_digplen(s) ? 0 : 2);
	s == 0 && param.accuracy == 0 ? param.temp = 0 : 0;
	if (param.accuracy <= param.temp && param.temp < param.width)
		param = ft_prite(param.flag == 0 || (param.flag == 1 && param.accuracy >= 0) ?\
		3 : param.flag,param.width - param.temp, s, param);
	else if (param.temp < param.accuracy && param.width <= param.accuracy)
		param = ft_prite(1, param.accuracy - param.temp, s, param);
	else if (param.temp >= param.accuracy && param.temp >= param.width)
		param = ft_prite(0, 0, s, param);
	else if (param.temp < param.accuracy && param.accuracy < param.width)
	{
		if (param.flag != 2)
			param = ft_prite(4, param.width - param.accuracy, s, param);
		param = ft_prite(1, param.accuracy - param.temp, s, param);
		if (param.flag == 2)
			param = ft_prite(4, param.width - param.accuracy, s, param);
	}
	return (param);
}

t_map		ft_prite(int format, int j, unsigned long str, t_map param)
{
	if (((!param.temp && param.width == 0) || (param.temp < param.accuracy && format == 1))\
	&& (param.length += 2))
		write(1, "0x", 2);
	if (!param.temp)
		j -= 2;
	if (j < 0)
		j = 0;
	if ((!format || format == 2) && param.temp)
		param.length += ft_p16ter(str, param, format, 0);
	if (format == 1)
		while (j-- && ++param.length)
			write(1, "0", 1);
	if (format && format != 1)
		while (j-- && ++param.length)
			write(1, " ", 1);
	if (format && format != 2 && format != 4 && param.temp)
		param.length += ft_p16ter(str, param, format, param.temp < param.accuracy && format == 1 ?\
		1 : 0);
	if (!param.temp && param.width > 0 && (param.length += 2))
		write(1, "0x", 2);
	return (param);
}

int			ft_p16ter(unsigned long n, t_map param, int format, int flag)
{
	char			n_char;

	!flag ? write(1, "0x", 2) : 0;
	if (n > 15)
		ft_p16ter(n / 16, param, format, 1);
	n_char = (n % 16) < 10 ? (n % 16) + '0' : (n % 16) + 'A' + 22;
	write(1, &n_char, 1);
	return (ft_digplen(n) + (param.temp < param.accuracy && format == 1 ? 0 : 2));
}
