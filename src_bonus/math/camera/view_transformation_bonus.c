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

#include "minirt_bonus.h"

t_matrix	view_transform(t_tuple from, t_tuple forward, t_tuple up)
{
	t_tuple		upn;
	t_tuple		left;
	t_tuple		true_up;
	t_matrix	orientation;
	t_matrix	trans_from;

	upn = normalize(up);
	left = cross(forward, upn);
	true_up = cross(left, forward);
	trans_from = create_translation_matrix(negate_tuple(from));
	orientation = create_matrix((double []){
			left.x, left.y, left.z, 0,
			true_up.x, true_up.y, true_up.z, 0,
			-forward.x, -forward.y, -forward.z, 0,
			0, 0, 0, 1,
			END_MATRIX
		});
	return (mult_matrices(orientation, trans_from));
}
