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
	m->rows[ROW1] = (float *)m->row_1;
	m->rows[ROW2] = (float *)m->row_2;
	m->rows[ROW3] = (float *)m->row_3;
	m->rows[ROW4] = (float *)m->row_4;
	return (*m);
}

t_3x3matrix	create_3x3_matrix(t_3x3matrix *m)
{
	m->rows[ROW1] = (float *)m->row_1;
	m->rows[ROW2] = (float *)m->row_2;
	m->rows[ROW3] = (float *)m->row_3;
	return (*m);
}

t_2x2matrix	create_2x2_matrix(t_2x2matrix *m)
{
	m->rows[ROW1] = (float *)m->row_1;
	m->rows[ROW2] = (float *)m->row_2;
	return (*m);
}
