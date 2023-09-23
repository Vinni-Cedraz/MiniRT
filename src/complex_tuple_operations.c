/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_tuple_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:54:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/09/23 19:59:23 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float vector_magnitude(const t_tuple vec)
{
	if (vec[W] == POINT)
		return (-1);
	return (hypot(hypot(vec[X], vec[Y]), vec[Z]));
}
