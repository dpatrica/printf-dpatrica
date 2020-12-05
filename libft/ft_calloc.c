/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:22:25 by dpatrica          #+#    #+#             */
/*   Updated: 2020/11/04 04:25:28 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*arr;

	i = 0;
	if ((arr = (unsigned char *)malloc(count * size)) == NULL)
		return (NULL);
	while (i < count * size)
	{
		arr[i] = '\0';
		i++;
	}
	return (arr);
}
