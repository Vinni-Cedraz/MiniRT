/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:50:34 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/09/24 23:39:57 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

// Applies the function ’f’ on each character of
// the string passed as argument, which as s[]'s index
// as its first argument.

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = -1;
	while (++i < (unsigned int)ft_strlen(s))
		f(i, (s + i));
}
