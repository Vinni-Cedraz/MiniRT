/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:07:22 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/08 11:13:48 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	translation(t_tuple point)
{
	t_matrix	translation;

	translation = create_4x4_matrix(&(t_matrix){
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1},
			.rows = {NULL}});
	translation.row_1[COL4] = point[X];
	translation.row_2[COL4] = point[Y];
	translation.row_3[COL4] = point[Z];
	return (translation);
}
