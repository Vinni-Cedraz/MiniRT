/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_determinants.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:45:12 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/04 17:52:57 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	_cofactor(const t_matrix m, int row, int col)
{
	t_matrix	sub;
	double		det;

	sub = _submatrix(m, row, col);
	det = _determinant(sub);
	return (pow(-1, row + col) * det);
}

double	_determinant(const t_matrix m)
{
	double	det;
	int		col;

	if (m.size == 2)
		return (_2x2determinant(m));
	det = 0;
	col = -1;
	while (++col < m.size)
		det += m.grid[0][col] * _cofactor(m, 0, col);
	return (det);
}
