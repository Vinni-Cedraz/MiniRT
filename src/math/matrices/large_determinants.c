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

double	_determinant(t_matrix m, const double *row)
{
	double determinant;

	determinant = 0;
	if (m.size == 2)
		return (_2x2determinant(m));
	determinant += *row * _determinant(_submatrix(m,0,0), row + 1);
	return (determinant);
}
static _Bool is_odd(int nb)
{
	return (nb % 2);
}

double	_3x3cofactor(const t_matrix m, int row, int col)
{
	double	_minor;
	double	_cofactor;

	_minor = _3x3minor(m, row, col);
	_cofactor = _minor;
	if (is_odd(row + col))
		_cofactor = _minor * -1;
	return (_cofactor);
}

double	_4x4cofactor(const t_matrix m, int row, int col)
{
	(void)m;
	(void)row;
	(void)col;
	return 0;
}
