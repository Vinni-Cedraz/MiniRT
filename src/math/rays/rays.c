/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:15:08 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/13 18:25:45 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	create_ray(t_tuple origin, t_tuple vector)
{
	const t_ray	ray = (t_ray){
		.origin = {origin[X], origin[Y], origin[Z], origin[W]},
		.direction = {vector[X], vector[Y], vector[Z], vector[W]},
	};

	return (ray);
}
