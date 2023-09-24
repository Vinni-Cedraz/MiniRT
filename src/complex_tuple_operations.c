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

#include "../include/minirt.h"

float	magnitude(const t_tuple vec)
{
	if (vec[W] != VECTOR)
		return (-1);
	return (hypot(hypot(vec[X], vec[Y]), vec[Z]));
}

short normalize(const t_tuple vec, t_tuple result)
{
	const float	mag = magnitude(vec);

	if (mag == 0 || vec[W] != VECTOR)
		return -1;
	result[X] = vec[X] / mag;
	result[Y] = vec[Y] / mag;
	result[Z] = vec[Z] / mag;
	return (0);
}

short dot(const t_tuple a, const t_tuple b, float dot_product)
{
	if (a[W] != VECTOR || b[W] != VECTOR)
		return (-1);
	dot_product = a[X] * b[X] + a[Y] * b[Y] + a[Z] * b[Z];
	return (0);
}
