/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:06:48 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 21:06:50 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	create_cylinder(void)
{
	const double	infinity = (1.0 / 0.0);
	t_shape			cyl;

	cyl = (t_shape){0};
	cyl.origin = create_point(0, 0, 0);
	cyl.type = CYLINDER;
	cyl.closed = FALSE;
	cyl.max = infinity;
	cyl.min = -infinity;
	set_transform(&cyl, create_identity_matrix());
	cyl.material = create_material();
	cyl.intersect = &intersect_cylinder;
	cyl.normal_at = &cylinder_normal_at;
	return (cyl);
}
