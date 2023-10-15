/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:28:57 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 15:12:07 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned char	t_uc;

static inline void		*aux_memcpy(void *dst, const void *src, size_t n);
static inline void		aux_swap(void *a, void *b, size_t size);

char	*ft_strrev(char *str, size_t strlen)
{
	t_counters	count;

	count.from_start = -1;
	count.from_end = strlen;
	while (++count.from_start < strlen / 2)
		aux_swap(&str[count.from_start], &str[--count.from_end], sizeof(char));
	return (str);
}

static inline void	aux_swap(void *a, void *b, size_t size)
{
	void	*tmp;

	tmp = malloc(size);
	aux_memcpy(tmp, a, size);
	aux_memcpy(a, b, size);
	aux_memcpy(b, tmp, size);
	free(tmp);
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
