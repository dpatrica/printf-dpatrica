/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:14:03 by dpatrica          #+#    #+#             */
/*   Updated: 2020/11/08 13:57:06 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	lena_src;

	if ((dst == NULL) && (src == NULL))
		return (0);
	lena_src = ft_strlen(src);
	if (!dstsize)
		return (lena_src);
	while (dst && *src && --dstsize)
		*dst++ = *src++;
	*dst = '\0';
	return (lena_src);
}
