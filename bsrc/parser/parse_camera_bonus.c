/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:25:40 by johmatos          #+#    #+#             */
/*   Updated: 2024/04/17 14:28:43 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"

int	parse_camera(t_token token, t_world *w)
{
	const t_tuple	from = parse_tuple(token.args[0], POINT);
	const t_tuple	forward = parse_tuple(token.args[1], VECTOR);
	const double	fov = parse_double(token.args[2], true);

	if (from.w == ERROR || forward.w == ERROR || fov == -DBL_MAX)
		return (ERROR);
	w->camera = create_camera(SIZEW, SIZEH, fov);
	w->camera.transform = view_transform(from, forward, w->camera.up);
	w->camera.cam_inv_trans = invert_matrix(w->camera.transform);
	return (0);
}
