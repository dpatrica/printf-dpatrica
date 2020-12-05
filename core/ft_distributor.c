/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distributor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:16:45 by dpatrica          #+#    #+#             */
/*   Updated: 2020/12/01 16:16:59 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_map	ft_distributor(t_map param, va_list ap)
{
	if (param.type == 'd' || param.type == 'i')
		param = ft_go_i_d(param, ap);
	if (param.type == 'u')
		param = ft_go_u(param, ap);
	if (param.type == 'c' || param.type == '%')
		param = ft_go_c_percent(param, ap);
	if (param.type == 's')
		param = ft_go_s(param, ap);
	if (param.type == 'p')
		param = ft_go_p(param, ap);
	if (param.type == 'x' || param.type == 'X')
		param = ft_go_x(param, ap);
	return (param);
}
