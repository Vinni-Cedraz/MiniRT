/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:20:22 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/17 12:20:27 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void	parse_sphere(t_token token, t_world *w)
{
	static const char types[6][20] = {
		"parse_ambient", "parse_camera", "parse_light",
		"parse_sphere", "parse_plane", "parse_cylinder"
	};

	printf("%s\n", types[token.type]);
	(void)token;
	(void)w;
}
