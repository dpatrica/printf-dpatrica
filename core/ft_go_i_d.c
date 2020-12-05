/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_i_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:17:17 by dpatrica          #+#    #+#             */
/*   Updated: 2020/12/01 16:17:19 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_map		ft_go_i_d(t_map param, va_list ap)
{
	int		i;

	param.type = va_arg(ap, int);
	i = ft_digitlen(param.type);
	param.type == 0 && param.accuracy == 0 ? i = 0 : 0;
	param.type < 0 && param.accuracy >= param.width ? i-- : 0;
	if (param.accuracy <= i && i < param.width)
		param = ft_inrite(param.flag == 0 || (param.flag == 1 && param.accuracy >= 0) ?\
		3 : param.flag,param.width - i, i, param);
	else if (i < param.accuracy && param.width <= param.accuracy)
		param = ft_inrite(1, param.accuracy - i, i, param);
	else if (i >= param.accuracy && i >= param.width)
		param = ft_inrite(0, 0, i, param);
	else if (i < param.accuracy && param.accuracy < param.width)
	{
		if (param.flag != 2)
			param = ft_inrite(4, param.width - param.accuracy, i, param);
		param = ft_inrite(1, param.accuracy - i, i, param);
		if (param.flag == 2)
			param = ft_inrite(4, param.width - param.accuracy, i, param);
	}
	return (param);
}

t_map		ft_inrite(int format, int j, int i, t_map param)
{
	long int	l;

	l = param.type;
	l *= -1;
	param.type < 0 && format == 2 && ++param.length ? write(1, "-", 1) : 0;
	param.type < 0 && format == 2 && param.accuracy > (i - 1) && j-- && ++param.length ?\
	write(1, "0", 1) : 0;
	if ((!format || format == 2) && i)
		param.length += ft_prtnbr(param.type < 0 && format == 2 ? l : param.type);
	if (format == 1)
	{
		param.type < 0 && ++param.length ? write(1, "-", 1) : 0;
		param.type < 0 && param.width > param.accuracy && param.accuracy >= 0 && ++param.length ?\
		write(1, "0", 1) : 0;
		while (j-- && ++param.length)
			write(1, "0", 1);
	}
	(param.type < 0 && format && format != 1) && ((format != 2 && format != 3) || \
	(format == 3 && i == param.accuracy)) ? j-- : 0;
	if (format && format != 1)
		while (j-- && ++param.length)
			write(1, " ", 1);
	param.type < 0 && format == 3 && i == param.accuracy && (param.length += 2) ?\
	write(1, "-0", 2) : 0;
	if (format && format != 2 && i && format != 4)
		param.length += ft_prtnbr(param.type < 0 && (format == 1 || (format == 3 && i == param.accuracy)) ?\
		l : param.type);
	return (param);
}

int			ft_prtnbr(long int n)
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
		ft_prtnbr(n_long / 10);
	n_char = n_long % 10 + '0';
	write(1, &n_char, 1);
	return (n == 2147483648 ? 10 : ft_digitlen(n));
}
