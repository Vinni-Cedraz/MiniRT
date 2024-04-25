/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:26:35 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/31 16:13:03 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_material	create_material(void)
{
	return ((t_material){
		.color = create_tuple(1, 1, 1, COLOR),
		.ambient = 0.1,
		.diffuse = 0.9,
		.specular = 0.9,
		.shininess = 200.0
	});
}

t_material	create_plane_material(void)
{
	return ((t_material){0});
}
