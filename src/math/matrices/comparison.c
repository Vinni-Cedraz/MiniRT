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
}

t_bool	_3x3matrices_eq(t_3x3matrix a, t_3x3matrix b)
{
}

t_bool	_2x2matrices_eq(t_2x2matrix a, t_2x2matrix b)
{
}

t_bool	tuples_neq(const double *result, const double *expected, int len)
{
}

t_matrix	mult_by_identity(t_matrix a)
{
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
