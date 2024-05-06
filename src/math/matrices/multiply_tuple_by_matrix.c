/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_tuple_by_matrix.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:04:28 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/24 21:20:58 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_tuple	arr_to_tuple(double arr[4]);

t_tuple	multiply_tuple_by_matrix(t_tuple a, t_matrix b)
{
	return ((t_tuple){
		.x = dot(a, arr_to_tuple(b.grid[0])),
		.y = dot(a, arr_to_tuple(b.grid[1])),
		.z = dot(a, arr_to_tuple(b.grid[2])),
		.w = a.w
	});
}

static inline t_tuple	arr_to_tuple(double arr[4])
{
	return ((t_tuple){arr[0], arr[1], arr[2], arr[3]});
}
