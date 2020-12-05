/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:14:19 by dpatrica          #+#    #+#             */
/*   Updated: 2020/11/07 14:22:09 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lena_dst;
	size_t	lena_src;
	size_t	sum_dst_src;

	if ((dst == NULL) && (src == NULL))
		return (0);
	lena_src = ft_strlen(src);
	if (dstsize < (lena_dst = ft_strlen(dst)))
		return (dstsize + lena_src);
	i = 0;
	sum_dst_src = lena_dst + lena_src;
	dstsize -= lena_dst;
	if (dstsize)
	{
		while (src[i] && (dstsize - 1) > i)
			dst[lena_dst++] = src[i++];
		dst[lena_dst] = '\0';
	}
	return (sum_dst_src);
}
