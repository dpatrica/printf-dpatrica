/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:22:40 by dpatrica          #+#    #+#             */
/*   Updated: 2020/11/03 20:46:12 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*arr;
	char	*rar;

	if ((arr = ft_calloc((ft_strlen(s1) + 1), sizeof(char))) == NULL)
		return (NULL);
	rar = arr;
	while (*s1)
		*arr++ = *s1++;
	return (rar);
}
