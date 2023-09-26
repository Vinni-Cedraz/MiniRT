/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:29:13 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/27 09:07:39 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_arr_size(void **arr, uint size)
{
	uint	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
