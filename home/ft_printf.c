/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:17:53 by dpatrica          #+#    #+#             */
/*   Updated: 2020/12/01 16:17:54 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_map	param;
	va_list	ap;

	if (format == NULL)
	{
		write(1, "(: NULL ? - LUL :)", 18);
		return (-1);
	}
	va_start(ap, format);
	param = ft_recursor(format, ap);
	va_end(ap);
	return (param.length);
}
