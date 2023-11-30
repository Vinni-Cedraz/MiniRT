/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:17:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/16 16:29:31 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	create_sphere(void)
{
	static t_short	call_counter;
	const t_sphere	sphere = {
		.origin = {0, 0, 0, POINT},
		.id = call_counter++,
		.type = SPHERE,
		._t = create_identity_matrix(),
		.inverse_t = create_identity_matrix(),
		.transposed_inverse_t = create_identity_matrix(),
		.material = create_material(),
	};

	return (sphere);
}
