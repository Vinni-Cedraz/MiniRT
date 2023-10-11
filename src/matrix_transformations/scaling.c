/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:25:48 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/11 16:31:24 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	create_scaling_matrix(const float x, const float y, const float z)
{
	const t_matrix res = {
			.row_1 = {x, 0, 0 ,0},
			.row_2 = {0, y, 0, 0},
			.row_3 = {0, 0, z, 0},
			.row_4 = {0, 0, 0, 1},
			.rows = {res.row_1, res.row_2, res.row_3, res.row_4
		}};

	return (res);
}
