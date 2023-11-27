/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_tuple_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:54:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/09/23 19:59:23 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	magnitude(const t_tuple vec)
{
	if (vec[W] != VECTOR)
		return (-1);
	return (hypot(hypot(vec[X], vec[Y]), vec[Z]));
}

short	normalize(const t_tuple vec, t_tuple result)
{
	const float	mag = magnitude(vec);

	if (mag == 0 || vec[W] != VECTOR)
		return (-1);
	result[X] = vec[X] / mag;
	result[Y] = vec[Y] / mag;
	result[Z] = vec[Z] / mag;
	result[W] = VECTOR;
	return (0);
}

float	dot(const t_tuple a, const t_tuple b)
{
	return (a[X] * b[X] + a[Y] * b[Y] + a[Z] * b[Z] + a[W] * b[W]);
}

short	cross(const t_tuple a, const t_tuple b, t_tuple cross_product)
{
	if (a[W] != VECTOR || b[W] != VECTOR)
		return (-1);
	cross_product[X] = a[Y] * b[Z] - a[Z] * b[Y];
	cross_product[Y] = a[Z] * b[X] - a[X] * b[Z];
	cross_product[Z] = a[X] * b[Y] - a[Y] * b[X];
	cross_product[W] = VECTOR;
	return (0);
}
