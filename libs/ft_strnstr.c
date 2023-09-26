/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:55:25 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 17:43:20 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	aux_strlen(const char *str);
static inline int		aux_strncmp(const char *s1, const char *s2, size_t n);
static inline int		within_limits(size_t i, size_t nstr_sz, size_t len);

char	*ft_strnstr(const char *str, const char *inner_str, size_t len)
{
	size_t	i;
	size_t	inner_str_sz;

	if (*inner_str == '\0')
		return ((char *)str);
	if (!len)
		return (NULL);
	inner_str_sz = aux_strlen(inner_str);
	i = 0;
	while (1)
	{
		if (i == len)
			return (NULL);
		if (str[i] == '\0')
			return (NULL);
		if (!aux_strncmp(str + i, inner_str, inner_str_sz))
			if (within_limits(i, inner_str_sz, len))
				break ;
		i++;
	}
	return ((char *)(str + i));
}

static inline int	within_limits(size_t i, size_t nlen, size_t len)
{
	if (i + nlen <= len)
		return (1);
	return (0);
}

static inline size_t	aux_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

static inline int	aux_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		difference;

	i = 0;
	difference = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (difference);
	difference = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (difference);
}
