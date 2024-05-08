/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:41:22 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/05/07 21:17:55 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix	create_matrix_of_cofactors(const t_matrix m);
static t_matrix	divide_each_element_by_det(t_matrix m, \
		const double det);

t_bool	is_invertible(t_matrix m)
{
	if (m.size == 4 && _determinant(m))
		return (true);
	return (false);
}

t_matrix	invert_matrix(t_matrix m)
{
	t_matrix		inverted_matrix;
	const double	det = _determinant(m);

	inverted_matrix = create_identity_matrix();
	if (is_invertible(m))
	{
		inverted_matrix = transpose_matrix(create_matrix_of_cofactors(m));
		inverted_matrix = divide_each_element_by_det(inverted_matrix, det);
		return (inverted_matrix);
	}
	return (m);
}

static t_matrix	create_matrix_of_cofactors(const t_matrix m)
{
	return (create_matrix((double []){
			_cofac(m, 0, 0), _cofac(m, 0, 1), _cofac(m, 0, 2), _cofac(m, 0, 3),
			_cofac(m, 1, 0), _cofac(m, 1, 1), _cofac(m, 1, 2), _cofac(m, 1, 3),
			_cofac(m, 2, 0), _cofac(m, 2, 1), _cofac(m, 2, 2), _cofac(m, 2, 3),
			_cofac(m, 3, 0), _cofac(m, 3, 1), _cofac(m, 3, 2), _cofac(m, 3, 3),
			END_MATRIX
		}));
}

static double	_div(t_matrix m, double d)
{
	static int	i;
	static int	j = -1;

	if (j == 3)
	{
		i++;
		j = -1;
	}
	if (i == 4)
		i = 0;
	return (m.grid[i][++j] / d);
}

static t_matrix	divide_each_element_by_det(t_matrix m, const double d)
{
	return (create_matrix((double []){
			_div(m, d), _div(m, d), _div(m, d), _div(m, d),
			_div(m, d), _div(m, d), _div(m, d), _div(m, d),
			_div(m, d), _div(m, d), _div(m, d), _div(m, d),
			_div(m, d), _div(m, d), _div(m, d), _div(m, d),
			END_MATRIX
		}));
}
