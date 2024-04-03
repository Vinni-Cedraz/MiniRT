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

double	magnitude(const t_tuple vec)
{
	t_tuple	v;
	double	result;

	if (vec.w)
		return (-42);
	v.x = vec.x * vec.x;
	v.y = vec.y * vec.y;
	v.z = vec.z * vec.z;
	result = sqrt(v.x + v.y + v.z);
	return (result);
}

t_tuple	normalize(const t_tuple vec)
{
	const double	mag = magnitude(vec);
	const t_tuple	result = {
		.x = vec.x / mag,
		.y = vec.y / mag,
		.z = vec.z / mag,
		.w = is_point(vec.w)
	};

	return (result);
}

double	dot(const t_tuple a, const t_tuple b)
{
	if (a.w && b.w)
		return (-42);
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_tuple	cross(const t_tuple a, const t_tuple b)
{
	const t_tuple	cross_product = {
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x,
		.w = is_point((short)(a.w + b.w))
	};

	return (cross_product);
}

short	is_point(short w)
{
	if (w > 0)
		return (-42);
	return (w);
}
