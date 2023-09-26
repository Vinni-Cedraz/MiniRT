/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:01:52 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/23 13:02:38 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned char	t_uc;

static void				*aux_memchr(const void *s, int c, size_t n);
static size_t			aux_strlen(const char *str);

char	*ft_strchr(const char *s, int c)
{
	return ((char *)aux_memchr(s, c, aux_strlen(s) + 1));
}

static inline void	*aux_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*str;

	chr = (unsigned char)c;
	str = (unsigned char *)s;
	if (!str)
		return (NULL);
	while (n--)
		if (*str++ == chr)
			return (str - 1);
	return (NULL);
}

static inline size_t	aux_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}
