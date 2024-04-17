/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:04:11 by johmatos          #+#    #+#             */
/*   Updated: 2024/04/17 12:20:34 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_light(t_token token, t_world *w)
{
	static const char types[6][20] = {
		"parse_ambient", "parse_camera", "parse_light",
		"parse_sphere", "parse_plane", "parse_cylinder"
	};

	printf("%s\n", types[token.type]);
	(void)token;
	(void)w;
}
