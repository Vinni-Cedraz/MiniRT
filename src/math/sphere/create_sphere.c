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

	sphere.radius = 1;
	sphere.origin = create_point(0, 0, 0);
	sphere.type = SPHERE;
	sphere._t = create_identity_matrix();
	sphere.inverse_t = create_identity_matrix();
	sphere.trans_inv = create_identity_matrix();
	sphere.material = create_material();
	sphere.dis_to_ray = create_vector(0, 0, 0);
	sphere.intersect = &intersect_sphere;
	sphere.normal_at = &sphere_normal_at;
	return (sphere);
}
