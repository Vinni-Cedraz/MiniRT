/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:31:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/05/11 10:30:56 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			aux_strlcat(char *dst, const char *src, size_t size);
static size_t			aux_strlcpy(char *dst, const char *src, size_t size);
static size_t			aux_strlen(const char *str);
static void				*aux_memcpy(void *dst, const void *src, size_t n);

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	len = aux_strlen(s1) + aux_strlen(s2) + 1;
	res = malloc(len);
	aux_strlcpy(res, s1, len);
	aux_strlcat(res, s2, len);
	return (free((char *)s1), free((char *)s2), res);
}

static inline size_t	aux_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

static inline void	*aux_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	i = -1;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (++i < n)
		*(dest + i) = *(source + i);
	return (dest);
}

static inline size_t	aux_strlcpy(char *dst, const char *src, size_t size)
{
	if (aux_strlen(src) + 1 < size)
		return (aux_strlen(aux_memcpy(dst, src, aux_strlen(src) + 1)));
	if (!size)
		return (aux_strlen(src));
	aux_memcpy(dst, src, size - 1);
	*(dst + size - 1) = '\0';
	return (aux_strlen(src));
}

static inline size_t	aux_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_sz;

	dst_sz = aux_strlen(dst);
	if (size < dst_sz + 1 || size == 0)
		dst_sz = size;
	if (size > dst_sz)
		aux_strlcpy(dst + dst_sz, src, size - dst_sz);
	return (dst_sz + aux_strlen(src));
}
