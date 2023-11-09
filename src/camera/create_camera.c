/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:10:15 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/09 11:21:17 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	create_camera(int hsize, int vsize, float field_of_view)
{
	const t_camera	c = {
		.hsize = hsize,
		.vsize = vsize,
		.field_of_view = field_of_view,
		.pixel_size = 1,
		.transform = create_identity_matrix(),
	};

	return ((t_camera)c);
}
