/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:07:51 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 21:07:54 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	create_sphere(void)
{
	t_shape		sphere;

	sphere = (t_shape){0};
	sphere.type = SPHERE;
	sphere.radius = 1;
	sphere.origin = create_point(0, 0, 0);
	set_transform(&sphere, create_identity_matrix());
	sphere.material = create_material();
	sphere.intersect = &intersect_sphere;
	sphere.normal_at = &sphere_normal_at;
	return (sphere);
}
