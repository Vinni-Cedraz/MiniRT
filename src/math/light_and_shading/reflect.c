/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:31:35 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 21:31:38 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	t_tuple			reflected_vector;
	const double	dot_prod = dot(in, normal);
	const t_tuple	normal_by_dot = multiply_tuple_by_scalar(normal, dot_prod);
	const t_tuple	expression = multiply_tuple_by_scalar(normal_by_dot, 2);

	reflected_vector = subtract_tuples(in, expression);
	return (reflected_vector);
}
