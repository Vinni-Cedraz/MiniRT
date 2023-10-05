/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:41:22 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/05 16:07:32 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	create_matrix_of_cofactors(t_matrix m);
t_matrix	divide_transposed_matrix_by_determinant_of_the_original(t_matrix m);

t_matrix	invert_matrix(t_matrix m)
{
	t_matrix	cofact_mat;
	t_matrix	transposed_cofact_mat;
	t_matrix	res;

	cofact_mat = create_matrix_of_cofactors(m);
	transposed_cofact_mat = transpose_matrix(cofact_mat);
	res = divide_transposed_matrix_by_determinant_of_the_original(m);
	return (res);
}

t_matrix	create_matrix_of_cofactors(t_matrix m)
{
	int			i;
	t_matrix	res;

	i = -1;
	while (++i < 4)
	{
		res.row_1[i] = _4x4cofactor(m, ROW1, i);
		res.row_2[i] = _4x4cofactor(m, ROW2, i);
		res.row_3[i] = _4x4cofactor(m, ROW3, i);
		res.row_4[i] = _4x4cofactor(m, ROW4, i);
	}
	return (res);
}

t_matrix	divide_transposed_matrix_by_determinant_of_the_original(t_matrix m)
{
	int			i;
	t_matrix	res;
	const float	determinant = _4x4determinant(m);

	i = 0;
	while (++i < 4)
	{
		res.row_1[i] = m.row_1[i] / determinant;
		res.row_2[i] = m.row_2[i] / determinant;
		res.row_3[i] = m.row_3[i] / determinant;
		res.row_4[i] = m.row_4[i] / determinant;
	}
	return (res);
}
