/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:28:46 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 16:41:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned char	t_uc;

static inline void		*aux_ft_memcpy(void *dst, const void *src, size_t n);

void	ft_swap(void *a, void *b, size_t size)
{
	void	*tmp;

	tmp = malloc(size);
	aux_ft_memcpy(tmp, a, size);
	aux_ft_memcpy(a, b, size);
	aux_ft_memcpy(b, tmp, size);
	free(tmp);
}

static inline void	*aux_ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		*(((t_uc *)dst) + i) = *(((t_uc *)src) + i);
	return (dst);
}
