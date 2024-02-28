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
}

t_3x3matrix	_4x4submatrix(const t_matrix m, int row_to_del, int col_to_delete)
{
}

void	subrow(t_tuple row, int col_to_delete, double subrow[], int len)
{
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
