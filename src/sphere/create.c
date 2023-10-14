/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:17:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/14 17:21:51 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	create_sphere(void)
{
	static t_short	call_counter;
	const t_sphere	sphere = {
		.origin = {0, 0, 0, POINT},
		.id = call_counter++,
		.radius = 1
	};

	return (sphere);
}
