/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:25:40 by johmatos          #+#    #+#             */
/*   Updated: 2024/04/17 11:30:04 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_camera(t_token token, t_world *w)
{
	static const char types[6][20] = {
		"parse_ambient", "parse_camera", "parse_light",
		"parse_sphere", "parse_plane", "parse_cylinder"
	};

	printf("%s\n", types[token.type]);
	(void)token;
	(void)w;
}
