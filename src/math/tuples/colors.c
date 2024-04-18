/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:23:47 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/18 16:24:26 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	multiply_colors(const t_tuple a, const t_tuple b)
{
	return ((t_tuple){
		.x = a.x * b.x,
		.y = a.y * b.y,
		.z = a.z * b.z,
		.w = COLOR
	});
}

t_tuple	normalize_color(const t_tuple a)
{
	return (create_tuple(a.x / 255, a.y / 255, a.z / 255, COLOR));
}
