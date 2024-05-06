/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tuple_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:22:09 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/09/23 15:22:13 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	add_tuples(const t_tuple a, const t_tuple b)
{
	const t_tuple	result = {
		a.x + b.x,
		a.y + b.y,
		a.z + b.z,
		(short)(a.w + b.w)
	};

	return (result);
}

t_tuple	subtract_tuples(const t_tuple a, const t_tuple b)
{
	const t_tuple	result = {
		a.x - b.x,
		a.y - b.y,
		a.z - b.z,
		(short)(a.w - b.w)
	};

	return (result);
}

t_tuple	negate_tuple(const t_tuple a)
{
	const t_tuple	result = {
		-a.x,
		-a.y,
		-a.z,
		a.w
	};

	return (result);
}

t_tuple	multiply_tuple_by_scalar(const t_tuple a, const double scalar)
{
	const t_tuple	res = {
		.x = a.x * scalar,
		.y = a.y * scalar,
		.z = a.z * scalar,
		.w = is_point(a.w)
	};

	return (res);
}
