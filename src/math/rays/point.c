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

void	get_position(t_ray ray, float t, t_tuple result)
{
	t_tuple	distance;

	multiply_tuple_by_scalar(ray.direction, t, distance);
	add_tuples(ray.origin, distance, result);
}
