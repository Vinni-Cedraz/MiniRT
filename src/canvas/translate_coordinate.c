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



#include "../../tests/tester.h"

#define scenario1 CYAN \
"\nGiven point(0, 0, 0, POINT)\n"\
"And canvas(500, 500)\n" \
"And p ← translate_coordinate(point, canvas)\n " \
"Then p = point(250, 250, 0, POINT)\n"RESET


Test(putting_it_together, translate_coordinate , .description = scenario1)
{
	t_tuple point = {0,0,0, POINT};
	t_canvas canvas = {500,500};
	t_tuple p = translate_coordinate(point, canvas);
	t_tuple expected = {250,250,0, POINT};
	
	cr_expect_tuple_eq(p, expected);
}
