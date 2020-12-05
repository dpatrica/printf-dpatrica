/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:13:11 by dpatrica          #+#    #+#             */
/*   Updated: 2020/10/30 19:41:14 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*reso;

	reso = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (*((char*)reso + i) == c)
			return (reso + i);
		i++;
	}
	return (NULL);
}
