/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:41:48 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/21 15:41:54 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	create_plane(void)
{
	static t_short	call_counter;
	const t_plane	plane = {
		.origin = {0, 0, 0, POINT},
		.id = call_counter++,
		.type = PLANE,
		._t = create_identity_matrix(),
		.inverse_t = create_identity_matrix(),
		.transposed_inverse_t = create_identity_matrix(),
		.material = create_plane_material(),
	};

	return (plane);
}
