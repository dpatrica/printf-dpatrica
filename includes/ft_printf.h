/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:17:58 by dpatrica          #+#    #+#             */
/*   Updated: 2020/12/01 16:17:59 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

typedef struct	s_struct
{
	int				flag;
	long int		width;
	long int		accuracy;
	int				type;
	int				length;
	int				temp;
}				t_map;
int				ft_printf(const char *format, ...);
int				ft_valid(int c);
t_map			ft_rwrite(const char **format, t_map param);
t_map			ft_parser(const char **format, t_map param, va_list ap);
t_map			ft_distributor(t_map param, va_list ap);
t_map			ft_fornull(t_map param);
t_map			ft_recursor(const char *format, va_list ap);
t_map			ft_go_i_d(t_map param, va_list ap);
t_map			ft_go_u(t_map param, va_list ap);
t_map			ft_go_s(t_map param, va_list ap);
t_map			ft_go_c_percent(t_map p, va_list ap);
t_map			ft_go_x(t_map param, va_list ap);
t_map			ft_go_p(t_map param, va_list ap);
t_map			ft_inrite(int format, int j, int i, t_map param);
t_map			ft_unrite(int format, int j, unsigned int s, t_map param);
t_map			ft_chrite(int format, int j, char *str, t_map p);
t_map			ft_u16ite(int format, int j, unsigned int str, t_map param);
t_map			ft_prite(int format, int j, unsigned long str, t_map param);
int				ft_prtnbr(long int n);
int				ft_unprtnbr(unsigned int n);
int				ft_prtstr(char *str, int i);
int				ft_put16(unsigned int n, int type);
int				ft_p16ter(unsigned long n, t_map param, int format, int flag);

#endif
