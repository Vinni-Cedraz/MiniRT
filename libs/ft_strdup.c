/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:35:43 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 17:47:20 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	aux_strlen(const char *str);
static inline size_t	aux_strlcpy(char *dst, const char *src, size_t len);
static inline void	*aux_memcpy(void *dst, const void *src, size_t n);

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		s_len;

	s_len = aux_strlen(s);
	dest = (char *)malloc(s_len + 1);
	aux_strlcpy(dest, s, s_len + 1);
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

static inline size_t	aux_strlcpy(char *dst, const char *src, size_t len)
{
	if (aux_strlen(src) + 1 < len)
		return (aux_strlen(aux_memcpy(dst, src, aux_strlen(src) + 1)));
	if (!len)
		return (aux_strlen(src));
	aux_memcpy(dst, src, len - 1);
	*(dst + len - 1) = '\0';
	return (aux_strlen(src));
}
