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

// First string on token.args represents the t_tuple from, the second one is the
// t_tuple forward and the third one is the fov this function parses the token
// to initialize the camera from the world struct when this function is called
// it is guaranteed that the t_token type is a camera, no need to check
void	parse_camera(t_token token, t_world *w)
{
	const t_tuple from = parse_tuple(token.args[0], POINT);
	const t_tuple forward = parse_tuple(token.args[1], VECTOR);

	printf("%s\n", types[token.type]);
	print_tuple(from);
	print_tuple(forward);
	w->camera.transform = view_transform(from, forward, w->camera.up);
}
