/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:10:26 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/10/02 15:01:11 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_counter(char const *s, char c)
{
	int		counter;
	char	state;

	state = 0;
	counter = 0;
	while (*s)
	{
		if (*s != c && state == 0)
		{
			state = 1;
			counter++;
		}
		else if (*s == c)
			state = 0;
		s++;
	}
	return (counter);
}
