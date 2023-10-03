/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:39:54 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/03 18:51:07 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_col(t_3x3_matrix b, int col_idx, t_tuple col);

int	_2x2determinant(t_2x2_matrix m)
{
	return (m.row_1[X] * m.row_2[Y] - m.row_2[X] * m.row_1[Y]);
}

t_2x2_matrix submatrix(t_3x3_matrix m, int row_idx, int col_idx)
{
	t_2x2_matrix res = {0};

	return (res);
}

static inline void	init_col(t_3x3_matrix b, int col_idx, t_tuple col)
{
	col[X] = b.row_1[col_idx];
	col[Y] = b.row_2[col_idx];
	col[Z] = b.row_3[col_idx];
}
