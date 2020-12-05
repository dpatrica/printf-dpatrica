/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:01:11 by dpatrica          #+#    #+#             */
/*   Updated: 2020/11/05 00:49:43 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	verni_lenu(char const *s1, char const *set, size_t le, size_t i)
{
	size_t	j;

	j = 0;
	while ((s1[le] && set[j]) && (le > i))
	{
		if (s1[le] == set[j])
		{
			j = 0;
			le--;
			continue ;
		}
		j++;
	}
	return (le);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	lena_s1;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	lena_s1 = ft_strlen(s1) - 1;
	while (s1[i] && set[j])
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i++;
			continue ;
		}
		j++;
	}
	j = 0;
	return (ft_substr(s1, i, verni_lenu(s1, set, lena_s1, i) - i + 1));
}
