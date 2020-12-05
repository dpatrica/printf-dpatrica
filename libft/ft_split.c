/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 02:43:13 by dpatrica          #+#    #+#             */
/*   Updated: 2020/11/08 19:24:36 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	koll_ptr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if ((*s == c) && (*(s + 1) != c) && (*(s + 1) != '\0'))
			i++;
		else if (*s != c && i == 0)
			i++;
		s++;
	}
	return (i);
}

static size_t	start_str(char **s, int c)
{
	size_t	i;

	i = 0;
	while (**s)
	{
		if (**s != c)
			return (i);
		(*s)++;
		i++;
	}
	return (0);
}

static size_t	kol_str(char **s, int c)
{
	size_t	i;

	i = 0;
	while (**s)
	{
		if ((**s == c) && (i != 0))
			return (i);
		(*s)++;
		i++;
	}
	return (i);
}

static char		**split_free(size_t i, char **arr)
{
	while (i--)
		free(arr[i]);
	free(arr);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**arr;
	char	*p_str;
	size_t	i;
	size_t	start_lena;
	size_t	kol_lena;

	if (!s)
		return (NULL);
	if ((arr = ft_calloc(koll_ptr(s, c) + 1, sizeof(char*))) == NULL)
		return (NULL);
	i = 0;
	p_str = (char*)s;
	start_lena = 0;
	kol_lena = 0;
	while (koll_ptr(s, c) > i)
	{
		start_lena = start_str(&p_str, c) + kol_lena + start_lena;
		kol_lena = kol_str(&p_str, c);
		if ((arr[i] = ft_substr(s, start_lena, kol_lena)) == NULL)
			return (split_free(i, arr));
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
