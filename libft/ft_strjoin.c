/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:12:13 by dpatrica          #+#    #+#             */
/*   Updated: 2020/11/04 18:28:53 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	char	*rar;
	size_t	schr;

	if (!s1 || !s2)
		return (NULL);
	schr = sizeof(char);
	if ((arr = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, schr)) == NULL)
		return (NULL);
	rar = arr;
	while (*s1)
		*arr++ = *s1++;
	while (*s2)
		*arr++ = *s2++;
	return (rar);
}
