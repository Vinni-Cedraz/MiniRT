/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrices.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:22:41 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/07 10:08:46 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	subrow(t_tuple row, int col_to_delete, double subrow[], int n);

t_2x2matrix	_3x3submatrix(const t_3x3matrix m, int row_to_del, int col_to_del)
{
	t_2x2matrix	res;
	int			m_idx;
	int			res_idx;

	m_idx = 0;
	res_idx = 0;
	res = create_2x2_matrix(&res);
	while (m_idx != 3)
	{
		if (m_idx == row_to_del)
		{
			m_idx++;
			continue ;
		}
		subrow(m.rows[m_idx++], col_to_del, res.rows[res_idx++], 3);
	}
	return (res);
}

t_3x3matrix	_4x4submatrix(const t_matrix m, int row_to_del, int col_to_delete)
{
	t_3x3matrix	res;
	int			m_idx;
	int			res_idx;

	m_idx = 0;
	res_idx = 0;
	res = create_3x3_matrix(&res);
	while (m_idx != 4)
	{
		if (m_idx == row_to_del)
		{
			m_idx++;
			continue ;
		}
		subrow(m.rows[m_idx++], col_to_delete, res.rows[res_idx++], 4);
	}
	return (res);
}

void	subrow(t_tuple row, int col_to_delete, double subrow[], int len)
{
	int	i;
	int	j;

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
