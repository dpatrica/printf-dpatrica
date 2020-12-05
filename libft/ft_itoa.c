/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:52:55 by dpatrica          #+#    #+#             */
/*   Updated: 2020/11/08 12:42:06 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*arr;
	size_t		lena;
	size_t		flag;
	long int	reza;
	long int	reso;

	lena = 1;
	flag = 0;
	reza = n;
	if ((reza < 0) && (++flag))
		reza *= -1;
	reso = reza;
	while ((reza > 9) && (lena++))
		reza = reza / 10;
	if ((arr = ft_calloc(lena + flag + 1, sizeof(char))) == NULL)
		return (NULL);
	if (flag == 1)
		arr[0] = '-';
	lena += flag;
	while (lena-- && (reso || !flag))
	{
		arr[lena] = (reso % 10) + '0';
		reso = reso / 10;
	}
	return (arr);
}
