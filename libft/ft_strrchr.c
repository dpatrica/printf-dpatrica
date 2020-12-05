/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:15:12 by dpatrica          #+#    #+#             */
/*   Updated: 2020/11/01 22:49:24 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (c != '\0')
	{
		while (i > 0)
		{
			i--;
			if (*((char*)s + i) == (char)c)
				return ((char*)s + i);
		}
	}
	else
		return ((char*)s + i);
	return (NULL);
}
