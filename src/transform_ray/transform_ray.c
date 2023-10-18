/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:30:58 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/18 16:40:04 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray transform_ray(t_ray ray, t_matrix matrix)
{
	multiply_tuple_by_matrix(ray.origin, matrix, ray.origin);
	multiply_tuple_by_matrix(ray.direction, matrix, ray.direction);
	return (ray);
}
