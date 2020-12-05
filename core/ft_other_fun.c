/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:17:44 by dpatrica          #+#    #+#             */
/*   Updated: 2020/12/01 16:17:45 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_map		ft_fornull(t_map param)
{
	param.flag = 0;
	param.width = 0;
	param.accuracy = -1;
	param.type = 0;
	param.temp = 0;
	return (param);
}

t_map		ft_rwrite(const char **format, t_map param)
{
	int i;

	i = 0;
	if (param.type != -1)
	{
		while ((**format != '%' || (**format == '%' && *(*format + 1) == '%')) &&\
		(**format && ++i))
		{
			write(1, &*(*format)++, 1);
			**format == '%' && *(*format - 1) == '%' ? (*format)++ : 0;
		}
	}
	else
	{
		write(1, "|E.R.R.O.R___This type----> ", 28);
		while (**format != '%' && **format && ++i)
			write(1, &*(*format)++, 1);
		write(1, " <----is invalid!___E.R.R.O.R|next format:", 42);
		while (**format && ++i)
			write(1, &*(*format)++, 1);
		param.length += 70;
	}
	param.length += i;
	if (**format)
		(*format)++;
	return (param);
}

int			ft_valid(int c)
{
	char	*type;

	type = "diucspxX%";
	while (*type)
	{
		if (*type == (char)c)
			return (1);
		type++;
	}
	return (0);
}
