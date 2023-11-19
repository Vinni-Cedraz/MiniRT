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

void	sphere_normal_at(const t_sphere *sphere, const t_tuple wrld_p, t_tuple normal)
{
	t_tuple	obj_point;
	t_tuple	obj_nrml;
	t_tuple	wlrd_nrml;

	multiply_tuple_by_matrix(wrld_p, sphere->inverse_t, obj_point);
	subtract_tuples(obj_point, (t_tuple){0, 0, 0, POINT}, obj_nrml);
	multiply_tuple_by_matrix(obj_nrml, sphere->transposed_inverse_t, wlrd_nrml);
	wlrd_nrml[W] = VECTOR;
	normalize(wlrd_nrml, normal);
}
