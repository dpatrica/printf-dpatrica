/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:17:27 by dpatrica          #+#    #+#             */
/*   Updated: 2020/12/01 16:17:29 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_map		ft_go_s(t_map param, va_list ap)
{
	int		i;
	char	*s;

	s = va_arg(ap, char*);
	param.type = ft_strlen(s);
	s == NULL ? (param.type = 6) : 0;
	i = 0;
	(param.accuracy < 0 || param.accuracy > param.type) && param.width > param.type ?\
	(i = (param.width - param.type)) : 0;
	param.accuracy >= 0 && param.width > param.accuracy ? (i = (param.width - param.accuracy)) : 0;
	if ((param.accuracy <= param.type && param.type < param.width) ||\
	(param.type < param.accuracy && param.width <= param.accuracy))
		param = ft_chrite(param.flag == 0 || (param.flag == 1 && param.accuracy >= 0) ?\
		3 : param.flag, i, s, param);
	else if ((param.accuracy < 0 && param.width <= param.type) ||\
	(param.width < param.accuracy && param.type >= param.accuracy))
		param = ft_chrite(0, 0, s, param);
	else if (param.type >= param.accuracy && param.type >= param.width)
		param = ft_chrite(param.flag == 0 && param.accuracy >= 0 ?\
		3 : param.flag, param.width - param.accuracy, s, param);
	else if (param.type < param.accuracy && param.accuracy < param.width)
	{
		if (param.flag != 2)
			param = ft_chrite(4, param.width - param.type, s, param);
		param = ft_chrite(0, param.accuracy - param.type, s, param);
		if (param.flag == 2)
			param = ft_chrite(4, param.width - param.type, s, param);
	}
	return (param);
}

t_map		ft_chrite(int format, int j, char *str, t_map p)
{
	if (!format || format == 2)
		p.length += ft_prtstr(str == NULL ? "(null)" : str, p.accuracy);
	if (format == 1)
		while (j-- && ++p.length)
			write(1, "0", 1);
	if (format && format != 1)
		while (j-- && ++p.length)
			write(1, " ", 1);
	if (format && format != 2 && format != 4)
		p.length += ft_prtstr(str == NULL ? "(null)" : str, p.accuracy);
	return (p);
}

int			ft_prtstr(char *str, int i)
{
	int j;

	j = 0;
	while (str[j] && i--)
		write(1, &str[j++], 1);
	return (j);
}
