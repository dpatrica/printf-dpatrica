/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:52:33 by dpatrica          #+#    #+#             */
/*   Updated: 2020/11/03 19:43:55 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if ((dst == NULL) && (src == NULL))
		return (NULL);
	while (i < n)
	{
		*((char*)dst + i) = *((char*)src + i);
		i++;
	}
	return (dst);
}
