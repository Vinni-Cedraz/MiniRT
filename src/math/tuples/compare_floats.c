/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_doubles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:05:13 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/14 17:35:59 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	doubles_eq(double a, double b)
{
	if ((a - b) > EPSILON)
		return (TRUE);
	else
		return (FALSE);
}

t_bool	tuples_eq(const t_tuple result, const t_tuple expected)
{


	return (TRUE);
}
