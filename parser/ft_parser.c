/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:19:03 by dpatrica          #+#    #+#             */
/*   Updated: 2020/12/01 16:19:04 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_map	ft_parser(const char **format, t_map param, va_list ap)
{
	while (**format == '0' && (*format)++)
		param.flag = 1;
	while (**format == '-' && (*format)++)
		param.flag = 2;
	while (**format == '-' || **format == '0')
		(*format)++;
	ft_isdigit(**format) ? *format += ft_digitlen(param.width = ft_atoi(*format)) : 0;
	if (**format == '*' && (*format)++)
		param.width = va_arg(ap, int);
	if (param.width < 0 && (param.flag = 2))
		param.width *= -1;
	if (**format == '.' && (*format)++ && !(param.accuracy = 0))
	{
		while (**format == '0')
			(*format)++;
		ft_mpldig(**format) ? *format += ft_digitlen(param.accuracy = ft_atoi(*format)) : 0;
		if (**format == '*' && (*format)++)
			param.accuracy = va_arg(ap, int);
	}
	param.type = ft_valid(**format) ? *(*format)++ : -1;
	return (param);
}
