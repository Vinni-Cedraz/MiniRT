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

static void	subrow(t_tuple row, int col_to_delete, float subrow[], int len);

t_2x2matrix	_3x3submatrix(t_3x3matrix m, int not_row, int col_to_delete)
{
	t_2x2matrix				res;
	const	float			(*m_row[]) = {
		m.row_1, m.row_2, m.row_3,
	};
	const	float			(*res_row[]) = {
		res.row_1, res.row_2,
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
				(float *)res_row[res_idx++], 3);
		else
			m_idx++;
	}
	return (res);
}

t_3x3matrix	_4x4submatrix(t_matrix m, int row_to_delete, int col_to_delete)
{
	t_3x3matrix				res;
	const	float			(*m_row[]) = {
		m.row_1, m.row_2, m.row_3, m.row_4,
	};
	const	float			(*res_row[]) = {
		res.row_1, res.row_2, res.row_3,
	};
	int						m_idx;
	int						res_idx;

	m_idx = 0;
	res_idx = 0;
	while (m_idx != 4)
	{
		if (m_idx != row_to_delete)
			subrow((float *)m_row[m_idx++],
				col_to_delete,
				(float *)res_row[res_idx++], 4);
		else
			m_idx++;
	}
	return (res);
}

void	subrow(t_tuple row, int col_to_delete, float subrow[], int len)
{
	int				i;
	int				j;

	j = 0;
	i = 0;
	while (i != len)
	{
		if (col_to_delete != i)
			subrow[j++] = row[i++];
		else
			i++;
	}
}

// #include "../../tests/tester.h"
// Test(submatrix, subrow) {
// 	t_tuple a = {1,5,0};
// 	t_tuple expected0 = {5,0};
// 	t_tuple expected1 = {1,0};
// 	t_tuple expected2 = {1,5};
// 	t_tuple result;
//
// 	subrow(a, 0, result, 3);
// 	cr_expect_tuple_eq(result, expected0);
// 	subrow(a, 1, result, 3);
// 	cr_expect_tuple_eq(result, expected1);
// 	subrow(a, 2, result, 3);
// 	cr_expect_tuple_eq(result, expected2);
// }
