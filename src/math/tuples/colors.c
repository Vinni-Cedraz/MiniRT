/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:24:21 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 21:24:23 by igenial          ###   ########.fr       */
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
