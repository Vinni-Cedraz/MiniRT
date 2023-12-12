/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tuples.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:27:15 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/14 17:49:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_point(t_tuple tuple)
{
	tuple[X] = 0;
	tuple[Y] = 0;
	tuple[Z] = 0;
	tuple[W] = POINT;
}

void	create_vector(t_tuple tuple)
{
	tuple[X] = 0;
	tuple[Y] = 0;
	tuple[Z] = 0;
	tuple[W] = VECTOR;
}

void	init_tuple(const t_tuple tuple, t_tuple res)
{
	res[X] = tuple[X];
	res[Y] = tuple[Y];
	res[Z] = tuple[Z];
	res[W] = tuple[W];
}

void	add_three_tuples(t_tuple ambient, t_tuple diffuse,
		t_tuple specular, t_tuple result)
{
	t_tuple	tmp_tuple;

	add_tuples(ambient, diffuse, tmp_tuple);
	add_tuples(tmp_tuple, specular, result);
}
