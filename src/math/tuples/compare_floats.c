/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_floats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:25:42 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 21:25:45 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	doubles_eq(double a, double b)
{
	if (fabs(a - b) > EPSILON)
		return (FALSE);
	else
		return (TRUE);
}

t_bool	low_precision_doubles_eq(double a, double b)
{
	if (fabs(a - b) > 1e-2)
		return (FALSE);
	else
		return (TRUE);
}

t_bool	tuples_eq(const t_tuple result, const t_tuple expected)
{
	if (doubles_eq(result.x, expected.x) == FALSE)
		return (FALSE);
	if (doubles_eq(result.y, expected.y) == FALSE)
		return (FALSE);
	if (doubles_eq(result.z, expected.z) == FALSE)
		return (FALSE);
	if (doubles_eq(result.w, expected.w) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	is_a_normalized_vector(t_tuple result)
{
	return (low_precision_doubles_eq(1, magnitude(result)));
}
