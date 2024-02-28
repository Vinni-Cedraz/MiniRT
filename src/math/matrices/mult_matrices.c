/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:30:24 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/03 11:48:35 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix	last_result(t_matrix *matrices[], const int idx);

t_matrix	mult_matrices(t_matrix a, t_matrix b)
{
}

void	multiply_tuple_by_matrix(const t_tuple row, t_matrix m, t_tuple res)
{
}

// mult_n_matrices
t_matrix	chain_transformations(t_matrix *matrices[])
{
}

static t_matrix	last_result(t_matrix *matrices[], const int idx)
{
}

// #include "../../tests/tester.h"
//
// t_matrix	a = {
// 	{1, 2, 3, 4},
// 	{0, 0, 0, 0},
// 	{0, 0, 0, 0},
// 	{0, 0, 0, 0},
// 	.rows = {a.row_1, a.row_2, a.row_3, a.row_4}
// };
// t_matrix b = {{-2, 1, 2, 3},
//               {3, 2, 1, -1},
//               {4, 3, 6, 5},
//               {1, 2, 7, 8},
//               .rows = {b.row_1, b.row_2, b.row_3, b.row_4}
// };
// t_matrix c = {{2, 4, 9, 1},
//               {0, -9, -2, 2},
//               {5, 2, 4, 3},
//               {-1, -5, -9, 12},
//               .rows = {b.row_1, b.row_2, b.row_3, b.row_4}
// };
// t_matrix d = {{10, 4, -9, 11},
//               {2, 12, -2, 5},
//               {-5, 2, 4, 3},
//               {-1, 5, -9, 12},
//               .rows = {b.row_1, b.row_2, b.row_3, b.row_4}
// };
//
// Test(operations, multiply_row_by_matrix)
// {
// 	t_tuple	res;
// 	t_tuple	expected = {18, 6, 48, 58};
// 	multiply_tuple_by_matrix(a.row_1, b, res);
// 	cr_expect_tuple_eq(expected, res);
// }
//
// Test(operations, chain_transformations)
// {
// 	t_matrix		expected;
// 	const t_matrix	*arr[] = {&a, &b, &c, &d, NULL};
// 	t_matrix		res;
//
// 	expected = mult_matrices(d, c);
// 	expected = mult_matrices(expected, b);
// 	expected = mult_matrices(expected, a);
// 	res = chain_transformations(arr);
// 	cr_assert_eq(TRUE, matrices_eq(res, expected));
// }
