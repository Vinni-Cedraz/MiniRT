/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transformation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:24:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/08 11:06:25 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix	orientation_matrix(t_tuple lft, t_tuple up, t_tuple frwd);
static t_matrix	move_scene_into_place(t_matrix *orientation, t_tuple from);

t_matrix	view_transform(t_tuple from, t_tuple forward, t_tuple up)
{
	t_tuple		left;
	t_tuple		true_up;
	t_matrix	orientation;
	const double	dot_product = dot(forward, up);

	if (doubles_eq(dot_product, 1))
		init_tuple(up, (t_tuple){0, 0, -1, VECTOR});
	else if (doubles_eq(dot_product, -1))
		init_tuple(up, (t_tuple){0, 0, 1, VECTOR});
	cross(forward, up, left);
	cross(left, forward, true_up);
	orientation = orientation_matrix(left, true_up, forward);
	return (move_scene_into_place(&orientation, from));
}

static t_matrix	orientation_matrix(t_tuple left, t_tuple truup, t_tuple forward)
{
	return (create_4x4_matrix(&(t_matrix){
			.row_1 = {left[X], left[Y], left[Z], 0},
			.row_2 = {truup[X], truup[Y], truup[Z], 0},
			.row_3 = {-forward[X], -forward[Y], -forward[Z], 0},
			.row_4 = {0, 0, 0, 1}, \
	}));
}

static t_matrix	move_scene_into_place(t_matrix *orientation, t_tuple from)
{
	const t_matrix	translation = create_translation_matrix(
			(t_tuple){-from[X], -from[Y], -from[Z]} \
	);

	return (mult_matrices(*orientation, translation));
}
