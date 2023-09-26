/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:03:39 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 18:01:38 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	aux_strlen(const char *str);

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = aux_strlen(s) + 1;
	while (i-- > 0 && s)
		if (s[i] == (char)c)
			return ((char *)s + i);
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
