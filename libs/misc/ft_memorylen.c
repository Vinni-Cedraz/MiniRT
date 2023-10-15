/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memorylen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:00:29 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/11 18:42:56 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_memorylen(void *ptr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (((char *)ptr)[i] == '\0')
			i++;
	}
	return (i);
}
