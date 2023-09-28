/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:07:30 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/09/28 15:10:02 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_buf	ft_simple_itoa(int num)
{
	int		j;
	int		k;
	char	tmp;
	t_buf	t;

	j = 0;
	k = 0;
	ft_bzero(t.buf, sizeof(t.buf));
	while (num != 0)
	{
		t.buf[j++] = (num % 10) + '0';
		num /= 10;
	}
	t.buf[j] = '\0';
	while (k < j / 2)
	{
		tmp = t.buf[k];
		t.buf[k] = t.buf[j - k - 1];
		t.buf[j - k - 1] = tmp;
		k++;
	}
	return (t);
}
