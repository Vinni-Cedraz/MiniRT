/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:42:53 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/01 16:54:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	matrices_eq(t_matrix a, t_matrix b)
{
	int	res;

	res = 0;
	res += tuples_neq(a.row_1, b.row_1, 4);
	res += tuples_neq(a.row_2, b.row_2, 4);
	res += tuples_neq(a.row_3, b.row_3, 4);
	res += tuples_neq(a.row_4, b.row_4, 4);
	return (!res);
}

t_bool	_3x3matrices_eq(t_3x3matrix a, t_3x3matrix b)
{
	int	res;

	res = 0;
	res += tuples_neq(a.row_1, b.row_1, 3);
	res += tuples_neq(a.row_2, b.row_2, 3);
	res += tuples_neq(a.row_3, b.row_3, 3);
	return (!res);
}

t_bool	_2x2matrices_eq(t_2x2matrix a, t_2x2matrix b)
{
	int	res;

	res = 0;
	res += tuples_neq(a.row_1, b.row_1, 2);
	res += tuples_neq(a.row_2, b.row_2, 2);
	return (!res);
}

t_bool	tuples_neq(const double *result, const double *expected, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (!doubles_eq(result[i], expected[i]))
			return (TRUE);
	}
	return (FALSE);
}

t_matrix	mult_by_identity(t_matrix a)
{
	return (mult_matrices(a, create_identity_matrix()));
}

// #include "../../tests/tester.h"
//
// Test(matrices_eq, _3x3_matrices_eq) {
// 	const t_3x3matrix a = {
// 		{1, 2, 3},
// 		{3, 2, 1},
// 		{0, 2, 0},
// 	};
// 	const t_3x3matrix b = {
// 		{1, 2, 3},
// 		{3, 2, 1},
// 		{0, 2, 0},
// 	};
// 	cr_assert_eq(TRUE, _3x3matrices_eq(a, b));
// }
//
// Test(matrices_eq, _2x2matrices_eq) {
// 	const t_2x2matrix c = {
// 		{1, 2},
// 		{2, 3},
// 	};
// 	const t_2x2matrix d = {
// 		{1, 2},
// 		{2, 3},
// 	};
// 	cr_assert_eq(TRUE, _2x2matrices_eq(c, d));
// }
