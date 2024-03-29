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

void	reflect(t_tuple vector, t_tuple normal, t_tuple _return)
{
	const double	dres = dot(vector, normal) * 2;
	t_tuple		result;

	multiply_tuple_by_scalar(normal, dres, result);
	subtract_tuples(vector, result, _return);
}
