/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:35:52 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 17:48:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static inline void	*aux_memcpy(void *dst, const void *src, size_t n);
static inline size_t	aux_strlen(const char *str);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (aux_strlen(src) + 1 < size)
		return (aux_strlen(aux_memcpy(dst, src, aux_strlen(src) + 1)));
	if (!size)
		return (aux_strlen(src));
	aux_memcpy(dst, src, size - 1);
	*(dst + size - 1) = '\0';
	return (aux_strlen(src));
}

static inline void	*aux_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	i = -1;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (++i < n)
		*(dest + i) = *(source + i);
	return (dest);
}

static inline size_t	aux_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}
