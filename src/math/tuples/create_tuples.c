/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tuples.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:27:15 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/14 17:49:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	create_point(float x, float y, float z)
{
	const t_tuple	tuple = {
		.x = x,
		.y = y,
		.z = z,
		.w = 1,
	};

	return (tuple);
}

t_tuple	create_vector(float x, float y, float z)
{
	const t_tuple	tuple = {
		.x = x,
		.y = y,
		.z = z,
		.w = 0,
	};

	return (tuple);
}

t_tuple	create_tuple(float x, float y, float z, short w)
{
	const t_tuple	tuple = {
		.x = x,
		.y = y,
		.z = z,
		.w = w,
	};

	return (tuple);
}

void	add_three_tuples(t_tuple ambient, t_tuple diffuse, t_tuple specular,
		t_tuple result)
{
	(void)ambient;
	(void)diffuse;
	(void)specular;
	(void)result;
}

void	tuple_to_arr(t_tuple a, double arr[4])
{
	arr[X] = a.x;
	arr[Y] = a.y;
	arr[Z] = a.z;
	arr[W] = a.w;
}
