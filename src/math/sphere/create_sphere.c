/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:17:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/20 19:27:52 by vcedraz-         ###   ########.fr       */
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
