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

#include "../include/minirt.h"

void	add_tuples(const t_tuple a, const t_tuple b, t_tuple result)
{
	result[X] = a[X] + b[X];
	result[Y] = a[Y] + b[Y];
	result[Z] = a[Z] + b[Z];
	result[W] = a[W] + b[W];
}

void	subtract_tuples(const t_tuple a, const t_tuple b, t_tuple result)
{
	result[X] = a[X] - b[X];
	result[Y] = a[Y] - b[Y];
	result[Z] = a[Z] - b[Z];
	result[W] = a[W] - b[W];
}

void	negate_tuple(const t_tuple a, t_tuple result)
{
	result[X] = -a[X];
	result[Y] = -a[Y];
	result[Z] = -a[Z];
	result[W] = -a[W];
}

void multiply_tuple_by_scalar(const t_tuple a, const float scalar, t_tuple res)
{

	res[X] = a[X] * scalar;
	res[Y] = a[Y] * scalar;
	res[Z] = a[Z] * scalar;
	res[W] = a[W] * scalar;
}
