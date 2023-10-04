/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrices.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:22:41 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/04 11:23:52 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	subrow(t_tuple row, int col_to_delete, float subrow[2]);

t_2x2matrix	_3x3submatrix(t_3x3matrix m, int not_row, int col_to_delete)
{
	t_2x2matrix				res;
	const	float			(*m_row[]) = {
		m.row_1,
		m.row_2,
		m.row_3,
	};
	const	float			(*res_row[]) = {
		res.row_1,
		res.row_2,
	};
	int						m_idx;
	int						res_idx;

	m_idx = 0;
	res_idx = 0;
	while (m_idx != 3)
	{
		if (m_idx != not_row)
			subrow((float *)m_row[m_idx++],
				col_to_delete,
				(float *)res_row[res_idx++]);
		else
			m_idx++;
	}
	return (res);
}

void	subrow(t_tuple row, int col_to_delete, float subrow[2])
{
	int				idx3x3;
	int				idx2x2;

	idx2x2 = 0;
	idx3x3 = 0;
	while (idx3x3 != 3)
	{
		if (col_to_delete != idx3x3)
			subrow[idx2x2++] = row[idx3x3++];
		else
			idx3x3++;
	}
}

// #include "../../tests/tester.h"
//
// Test(submatrix, subrow) {
// 	t_tuple a = {1,5,0};
// 	t_tuple expected0 = {5,0};
// 	t_tuple expected1 = {1,0};
// 	t_tuple expected2 = {1,5};
// 	t_tuple result;
//
// 	subrow(a, 0, result);
// 	cr_expect_tuple_eq(result, expected0);
// 	subrow(a, 1, result);
// 	cr_expect_tuple_eq(result, expected1);
// 	subrow(a, 2, result);
// 	cr_expect_tuple_eq(result, expected2);
// }
