/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_normals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:33:40 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/20 11:37:07 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	sphere_normal_at(t_sphere *sphere, const t_tuple wrld_p)
{
	t_tuple normal;

	normal = subtract_tuples(wrld_p,sphere->origin);
	return (normal);
}

void	plane_normal_at( \
		const t_shape *plane, const t_tuple wrld_p, t_tuple res)
{
	(void)plane;
	(void)wrld_p;
	(void)res;
}

void	cylinder_normal_at( \
		const t_shape *cyl, const t_tuple wrld_p, t_tuple res)
{
	(void)cyl;
	(void)wrld_p;
	(void)res;
}
