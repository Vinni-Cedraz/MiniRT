/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:31:11 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/24 19:31:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylinder	create_cylinder(void)
{
	static t_short		call_counter;
	const t_cylinder	cylinder = {
		.origin = {0, 0, 0, POINT},
		.id = call_counter++,
		.closed = FALSE,
		.type = CYLINDER,
		._t = create_identity_matrix(),
		.inverse_t = create_identity_matrix(),
		.transposed_inverse_t = create_identity_matrix(),
		.material = create_material(),
		.min = -INFINITY,
		.max = INFINITY,
	};

	return (cylinder);
}
