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

void	ft_simple_itoa(int num, char pxl_str[])
{
	int		j;
	int		k;
	char	tmp;

	j = 0;
	k = 0;
	while (num != 0)
	{
		pxl_str[j++] = (num % 10) + '0';
		num /= 10;
	}
	pxl_str[j] = '\0';
	while (k < j / 2)
	{
		tmp = pxl_str[k];
		pxl_str[k] = pxl_str[j - k - 1];
		pxl_str[j - k - 1] = tmp;
		k++;
	}
}
