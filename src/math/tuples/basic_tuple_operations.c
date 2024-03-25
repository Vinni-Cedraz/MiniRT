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

t_tuple	add_tuples(const t_tuple a, const t_tuple b)
{
	const t_tuple result = {a.x + b.x, a.y + b.y, a.z + b.z, (short)(a.w + b.w)};
	return (result);
}

t_tuple	subtract_tuples(const t_tuple a, const t_tuple b)
{
	const t_tuple result = {a.x - b.x, a.y - b.y, a.z - b.z, (short)(a.w - b.w)};
	return (result);
}

t_tuple	negate_tuple(const t_tuple a)
{
	const t_tuple result = {-a.x, -a.y, -a.z, a.w};
	return (result);
}

void	multiply_tuple_by_scalar(
		const t_tuple a, const double scalar, t_tuple re)
{
	(void)a;
	(void)scalar;
	(void)re;
}

void	multiply_colors(const t_tuple c1, const t_tuple c2, t_tuple result)
{
	(void)c1;
	(void)c2;
	(void)result;
}
