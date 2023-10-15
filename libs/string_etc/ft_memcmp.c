/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:00:43 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 17:43:39 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = -1;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (++i < n)
		if (*(a + i) != *(b + i))
			return (*(a + i) - *(b + i));
	return (0);
}
