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
	t_tuple v;
	double result;
	v.x = vec.x * vec.x;
	v.y = vec.y * vec.y;
	v.z = vec.z * vec.z;
	result = sqrt(v.x + v.y + v.z);
	return (result);
}
t_tuple	normalize(const t_tuple vec)
{
	const double mag = magnitude(vec);;
	const t_tuple result = {
			.x = vec.x/mag,
			.y = vec.y/mag,
			.z = vec.z/mag,
			.w = 0
	};
	return (result);
}

double	dot(const t_tuple a, const t_tuple b)
{
	(void)a;
	(void)b;
	return 0;
}

short	cross(const t_tuple a, const t_tuple b, t_tuple cross_product)
{
	(void)a;
	(void)b;
	(void)cross_product;
	return 0;
}
