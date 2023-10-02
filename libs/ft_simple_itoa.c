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
#include <stdio.h>
#include <string.h>

void	recursive_itoa(int num, t_buf *t);

t_buf	ft_simple_itoa(int num)
{
	t_buf	t;

	t.len = 0;
	ft_bzero(t.buf, 5);
	if (num == 0)
		t.buf[0] = '0';
	else
		recursive_itoa(num, &t);
	return (t);
}

void	recursive_itoa(int num, t_buf *t)
{
	if (num == 0)
		return ;
	recursive_itoa(num / 10, t);
	t->buf[t->len++] = (num % 10) + '0';
}

// #include <assert.h>
//
// int	main(void)
// {
// 	assert(!strcmp(ft_simple_itoa(0).buf, "0"));
// 	assert(!strcmp(ft_simple_itoa(1).buf, "1"));
// 	assert(!strcmp(ft_simple_itoa(10).buf, "10"));
// 	assert(!strcmp(ft_simple_itoa(100).buf, "100"));
// 	assert(!strcmp(ft_simple_itoa(498).buf, "498"));
// 	printf("ft_simple_itoa: "GREEN"OK\n"RESET);
// }
