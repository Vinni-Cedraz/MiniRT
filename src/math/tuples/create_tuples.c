/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tuples.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:26:50 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 21:26:52 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	create_point(double x, double y, double z)
{
	const t_tuple	tuple = {
		.x = x,
		.y = y,
		.z = z,
		.w = 1,
	};

	return (tuple);
}

t_tuple	create_vector(double x, double y, double z)
{
	const t_tuple	tuple = {
		.x = x,
		.y = y,
		.z = z,
		.w = 0,
	};

	return (tuple);
}

t_tuple	create_tuple(double x, double y, double z, double w)
{
	const t_tuple	tuple = {
		.x = x,
		.y = y,
		.z = z,
		.w = w,
	};

	return (tuple);
}

t_tuple	add_three_tuples(t_tuple a, t_tuple d, t_tuple s)
{
	const t_tuple	result = {
		a.x + d.x + s.x,
		a.y + d.y + s.y,
		a.z + d.z + s.z,
		COLOR
	};

	return (result);
}

void	tuple_to_arr(t_tuple a, double arr[4])
{
	arr[X] = a.x;
	arr[Y] = a.y;
	arr[Z] = a.z;
	arr[W] = a.w;
}
