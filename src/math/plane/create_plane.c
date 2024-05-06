/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:41:48 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/21 15:41:54 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include "minirt.h"

t_shape	create_plane(void)
{
	t_shape	plane;

	plane = (t_shape){0};
	plane.origin = create_point(0, 0, 0);
	plane.type = PLANE;
	plane.intersect = &intersect_plane;
	plane.normal_at = &plane_normal_at;
	plane.material = create_material();
	set_transform(&plane, create_identity_matrix());
	return (plane);
}

t_matrix	shape_view_transform(t_tuple from, t_tuple up)
{
	t_matrix	transform;
	t_tuple		right;
	t_tuple		forward;

	if (fabs(up.x) < 0.999)
		right = normalize(cross(up, create_vector(0, 1, 0)));
	else
		right = normalize(cross(up, create_vector(0, 0, 1)));
	forward = cross(right, up);
	transform = create_matrix((double []){
			right.x, up.x, forward.x, from.x,
			right.y, up.y, forward.y, from.y,
			right.z, up.z, forward.z, from.z,
			right.w, up.w, forward.w, from.w,
			END_MATRIX
		});
	return (transform);
}
