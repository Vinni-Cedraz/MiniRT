/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_tuple_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:26:30 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 21:26:32 by igenial          ###   ########.fr       */
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
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w));
}

t_tuple	cross(const t_tuple a, const t_tuple b)
{
	t_tuple	cross_product;

	if (is_point(a.w) || is_point(b.w))
		return (create_tuple(-42, -42, -42, -42));
	cross_product = (t_tuple){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x,
		.w = VECTOR
	};
	return (cross_product);
}

short	is_point(short w)
{
	if (w == POINT)
		return (-42);
	return (w);
}
