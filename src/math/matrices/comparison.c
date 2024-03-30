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
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < a.size)
	{
		while (j < a.size)
		{
			if (!doubles_eq(a.grid[i][j], b.grid[i][j]))
				return (false);
			j++;
		}
		i++;
		j = 0;
	}
	return (true);
}

t_bool	tuples_neq(const double *result, const double *expected, int len)
{
	(void)result;
	(void)expected;
	(void)len;
	return (FALSE);
}

t_matrix	mult_by_identity(t_matrix a)
{
	(void)a;
	return ((t_matrix){0});
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
