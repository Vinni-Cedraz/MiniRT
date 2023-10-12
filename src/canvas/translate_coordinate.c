/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_coordinate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:43:53 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/12 12:53:53 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	translate_coordinate(t_tuple point, t_canvas canvas, t_tuple res)
{
	const float	height = canvas.height;
	const float	width = canvas.width;

	res[X] = point [X] + width / 2;
	res[Y] = point[Y] + height / 2;
	res[Z] = point[Z];
	res[W] = point[W];
}

#include "../../tests/tester.h"

Test(putting_it_together, translate_coordinate, .description = scenario1)
{
	t_tuple 	res;
	t_tuple		point = {0, 0, 0, POINT};
	t_canvas	canvas = create_canvas(500, 500);
	t_tuple		expected = {250, 250, 0, POINT};
	
	translate_coordinate(point, canvas, res);
	cr_expect_tuple_eq(res, expected);
}
