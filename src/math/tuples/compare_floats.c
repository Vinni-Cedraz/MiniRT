/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_floats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:05:13 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/14 17:35:59 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	floats_eq(float a, float b)
{
	return (fabs(a - b) < EPSILON);
}

t_bool	tuples_eq(const t_tuple result, const t_tuple expected)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (!floats_eq(result[i], expected[i]))
			return (FALSE);
	}
	return (TRUE);
}
