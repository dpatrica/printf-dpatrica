/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:17:48 by dpatrica          #+#    #+#             */
/*   Updated: 2020/12/01 16:17:49 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_map	ft_recursor(const char *format, va_list ap)
{
	t_map	param;

	param.length = 0;
	while (*format)
	{
		param = ft_fornull(param);
		param = ft_rwrite(&format, param);
		if (*format)
			param = ft_parser(&format, param, ap);
		if (param.type == -1)
		{
			param = ft_rwrite(&format, param);
			break ;
		}
		if (param.type)
			param = ft_distributor(param, ap);
	}
	return (param);
}
