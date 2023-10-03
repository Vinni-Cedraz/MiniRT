/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:24:49 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/03 16:27:15 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	transpose_matrix(t_matrix a)
{
	const t_matrix	res = {
		.row_1[X] = a.row_1[X],
		.row_1[Y] = a.row_2[X],
		.row_1[Z] = a.row_3[X],
		.row_1[W] = a.row_4[X],
		.row_2[X] = a.row_1[Y],
		.row_2[Y] = a.row_2[Y],
		.row_2[Z] = a.row_3[Y],
		.row_2[W] = a.row_4[Y],
		.row_3[X] = a.row_1[Z],
		.row_3[Y] = a.row_2[Z],
		.row_3[Z] = a.row_3[Z],
		.row_3[W] = a.row_4[Z],
		.row_4[X] = a.row_1[W],
		.row_4[Y] = a.row_2[W],
		.row_4[Z] = a.row_3[W],
		.row_4[W] = a.row_4[W],
	};

	return ((t_matrix)res);
}
