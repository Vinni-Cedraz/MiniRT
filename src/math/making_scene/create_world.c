/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:26:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/30 17:31:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_world	create_world(void)
{
	return ((t_world){0});
}

t_world	default_world(void)
{
	return ((t_world){0});
}

void	add_object(t_world *w, t_shape *new_obj,
		int total_nb_of_objects_in_the_world)
{
	(void)w;
	(void)new_obj;
	(void)total_nb_of_objects_in_the_world;
}
