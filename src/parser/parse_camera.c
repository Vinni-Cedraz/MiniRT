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

#include "minirt.h"

int	parse_camera(t_token token, t_world *w)
{
	const t_tuple	from = parse_tuple(token.args[0], POINT);
	const t_tuple	forward = parse_tuple(token.args[1], VECTOR);
	const double	fov = parse_double(token.args[2]);

	if (from.w == ERROR || forward.w == ERROR || fov == -DBL_MAX)
		return (true);
	printf("%s\n", types[token.type]);
	w->camera = create_camera(SIZEW, SIZEH, fov);
	w->camera.transform = view_transform(from, forward, w->camera.up);
	return (false);
}
