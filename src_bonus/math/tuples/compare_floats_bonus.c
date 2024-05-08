/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_floats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:41:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/03/26 19:41:12 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

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
