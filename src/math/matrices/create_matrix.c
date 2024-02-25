/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 09:59:18 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/07 10:07:17 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	*create_4x4_matrix(t_matrix *m)
{
	t_matrix	*new_matrix;

	new_matrix = malloc(sizeof(t_matrix));
	init_tuple(m->row_1, new_matrix->row_1);
	init_tuple(m->row_2, new_matrix->row_2);
	init_tuple(m->row_3, new_matrix->row_3);
	init_tuple(m->row_4, new_matrix->row_4);
	new_matrix->rows[ROW1] = new_matrix->row_1;
	new_matrix->rows[ROW2] = new_matrix->row_2;
	new_matrix->rows[ROW3] = new_matrix->row_3;
	new_matrix->rows[ROW4] = new_matrix->row_4;
	return (new_matrix);
}

t_3x3matrix	*create_3x3_matrix(t_3x3matrix *m)
{
	t_3x3matrix	*new_matrix;

	new_matrix = malloc(sizeof(t_matrix));
	init_tuple(m->row_1, new_matrix->row_1);
	init_tuple(m->row_2, new_matrix->row_2);
	init_tuple(m->row_3, new_matrix->row_3);
	new_matrix->rows[ROW1] = new_matrix->row_1;
	new_matrix->rows[ROW2] = new_matrix->row_2;
	new_matrix->rows[ROW3] = new_matrix->row_3;
	return (new_matrix);
}

t_2x2matrix	*create_2x2_matrix(t_2x2matrix *m)
{
	t_2x2matrix	*new_matrix;

	new_matrix = malloc(sizeof(t_matrix));
	init_tuple(m->row_1, new_matrix->row_1);
	init_tuple(m->row_2, new_matrix->row_2);
	new_matrix->rows[ROW1] = new_matrix->row_1;
	new_matrix->rows[ROW2] = new_matrix->row_2;
	return (new_matrix);
}

t_matrix	*create_identity_matrix(void)
{
	return (create_4x4_matrix(&(t_matrix){
			.row_1 = {1, 0, 0, 0},
			.row_2 = {0, 1, 0, 0},
			.row_3 = {0, 0, 1, 0},
			.row_4 = {0, 0, 0, 1},
		}));
}
