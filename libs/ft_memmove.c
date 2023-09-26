/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 08:14:11 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 11:22:11 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void		*aux_memcpy(void *dst, const void *src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (!dst || !src || n == 0)
		return (dst);
	if (dst < src)
		aux_memcpy(dst, src, n);
	if (dst > src)
		while (n--)
			*(((char *)dst) + n) = *(((char *)src) + n);
	return (dst);
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
