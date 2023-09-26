/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexlow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:32:21 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/24 18:00:14 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	is_digit(int c);
static inline int	is_hexlow(int c);

int	ft_ishexlow(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (!is_digit(*s) && !is_hexlow(*s))
			return (0);
		s++;
	}
	return (1);
}

static inline int	is_digit(int c)
{
	return ('0' <= c && c <= '9');
}

static inline int	is_hexlow(int c)
{
	return ('a' <= c && c <= 'f');
}
