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

t_matrix	create_4x4_matrix(t_matrix *m)
{
	m->rows[ROW1] = m->row_1;
	m->rows[ROW2] = m->row_2;
	m->rows[ROW3] = m->row_3;
	m->rows[ROW4] = m->row_4;
	return (*m);
}

t_3x3matrix	create_3x3_matrix(t_3x3matrix *m)
{
	m->rows[ROW1] = m->row_1;
	m->rows[ROW2] = m->row_2;
	m->rows[ROW3] = m->row_3;
	return (*m);
}

t_2x2matrix	create_2x2_matrix(t_2x2matrix *m)
{
	m->rows[ROW1] = m->row_1;
	m->rows[ROW2] = m->row_2;
	return (*m);
}

t_matrix	create_identity_matrix(void)
{
	return (create_4x4_matrix(&(t_matrix){
			.row_1 = {1, 0, 0, 0},
			.row_2 = {0, 1, 0, 0},
			.row_3 = {0, 0, 1, 0},
			.row_4 = {0, 0, 0, 1},
		}));
}
