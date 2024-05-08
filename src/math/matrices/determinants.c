/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:15:46 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 21:15:50 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	_2x2determinant(t_matrix m);

double	_determinant(const t_matrix m)
{
	double	det;
	int		col;

	if (m.size == 2)
		return (_2x2determinant(m));
	det = 0;
	col = -1;
	while (++col < m.size)
		det += m.grid[0][col] * _cofac(m, 0, col);
	return (det);
}

static double	_2x2determinant(t_matrix m)
{
	double	ad;
	double	bc;

	ad = m.grid[0][0] * m.grid[1][1];
	bc = m.grid[1][0] * m.grid[0][1];
	return (ad - bc);
}

double	_cofac(const t_matrix m, int row, int col)
{
	return (pow(-1, row + col) * _minor(m, row, col));
}
