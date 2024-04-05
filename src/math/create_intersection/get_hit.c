/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:23:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/19 17:23:53 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				_arr_size(const t_intersection *arr[]);

t_intersection	_hit(const t_intersection *arr[])
{
	t_intersection			tmp;
	int						size;
	int						i;

	i = 0;
	size = _arr_size(arr);
	tmp.t = __INT_MAX__;
	tmp.object = NULL;
	while (i < size)
	{
		if (arr[i]->t < tmp.t && arr[i]->t > 0)
			tmp = *arr[i];
		i++;
	}
	return (tmp);
}

int	_arr_size(const t_intersection *arr[])
{
	int	counter;

	counter = 0;
	while (arr[counter] != NULL)
		counter++;
	return (counter);
}
