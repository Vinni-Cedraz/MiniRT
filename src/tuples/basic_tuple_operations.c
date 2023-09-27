/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tuple_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:22:09 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/09/23 15:22:13 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_tuples(const t_tuple a, const t_tuple b, t_tuple result)
{
	result[X] = a[X] + b[X];
	result[Y] = a[Y] + b[Y];
	result[Z] = a[Z] + b[Z];
	result[W] = a[W] + b[W];
	if (a[W] == COLOR && a[W] == COLOR)
		result[W] = COLOR;
}

void	subtract_tuples(const t_tuple a, const t_tuple b, t_tuple result)
{
	result[X] = a[X] - b[X];
	result[Y] = a[Y] - b[Y];
	result[Z] = a[Z] - b[Z];
	result[W] = a[W] - b[W];
	if (a[W] == COLOR && a[W] == COLOR)
		result[W] = COLOR;
}

void	negate_tuple(const t_tuple a, t_tuple result)
{
	result[X] = -a[X];
	result[Y] = -a[Y];
	result[Z] = -a[Z];
	result[W] = -a[W];
}

void	multiply_tuple_by_scalar(
		const t_tuple a, const float scalar, t_tuple re)
{
	re[X] = a[X] * scalar;
	re[Y] = a[Y] * scalar;
	re[Z] = a[Z] * scalar;
	re[W] = a[W] * scalar;
	if (a[W] == COLOR && a[W] == COLOR)
		re[W] = COLOR;
}

void	multiply_colors(const t_tuple c1, const t_tuple c2, t_tuple result)
{
	if (c1[W] != COLOR && c2[W] != COLOR)
		return ;
	result[R] = c1[R] * c2[R];
	result[G] = c1[G] * c2[G];
	result[B] = c1[B] * c2[B];
	result[W] = COLOR;
}
