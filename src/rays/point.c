/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:43:37 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/13 19:06:22 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_point_from_distance(t_ray ray, float distance, t_tuple _result)
{
	t_tuple	result;
	t_tuple	result2;

	multiply_tuple_by_scalar(ray.direction, distance, result);
	add_tuples(ray.origin, result, result2);
	_result[X] = result2[X];
	_result[Y] = result2[Y];
	_result[Z] = result2[Z];
	_result[W] = result2[W];
}
