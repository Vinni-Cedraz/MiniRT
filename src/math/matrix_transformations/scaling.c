/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:25:48 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/11 19:27:29 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	create_scaling_matrix(const double x, const double y, const double z)
{
	return (create_4x4_matrix(&(t_matrix){
			.row_1 = {x, 0, 0, 0},
			.row_2 = {0, y, 0, 0},
			.row_3 = {0, 0, z, 0},
			.row_4 = {0, 0, 0, 1},
		}));
}
