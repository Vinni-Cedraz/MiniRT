/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_normals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:33:40 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/20 11:37:07 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	normal_at(t_sphere *sphere, t_tuple p, t_tuple res)
{
	t_tuple	temp;

	subtract_tuples(p, sphere->origin, temp);
	normalize(temp, res);
}
