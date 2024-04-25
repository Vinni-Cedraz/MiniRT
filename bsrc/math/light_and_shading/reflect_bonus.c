/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:55:14 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/21 13:03:24 by johmatos         ###   ########.fr       */
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
