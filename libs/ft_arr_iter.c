/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:58:59 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/09/26 14:21:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2d_iter(void **ar, int n, t_function_ptr funct, t_ype tp)
{
	int	i;

	i = 0;
	while (i++ < n)
	{
		funct(&ar[i / n][i % n], tp);
	}
}
