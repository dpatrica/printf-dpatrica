/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:12:54 by dpatrica          #+#    #+#             */
/*   Updated: 2020/11/03 19:41:33 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if ((dst == NULL) && (src == NULL))
		return (NULL);
	if (dst < src)
	{
		while (i < len)
		{
			*((char*)dst + i) = *((char*)src + i);
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			len--;
			*((char*)dst + len) = *((char*)src + len);
		}
	}
	return (dst);
}
