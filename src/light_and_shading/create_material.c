/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:26:35 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/22 11:32:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material	create_material(void)
{
	return ((t_material){
		.color = {1, 1, 1, COLOR},
		.ambient = 0.1,
		.diffuse = 0.9,
		.specular = 0.9,
		.shininess = 200.0,
	});
}

void	set_material(t_tuple phong, t_tuple color, t_material *m)
{
	if (phong[AMBIENT] >= 0)
		m->ambient = phong[AMBIENT];
	if (phong[DIFFUSE] >= 0)
		m->diffuse = phong[DIFFUSE];
	if (phong[SPECULAR] >= 0)
		m->specular = phong[SPECULAR];
	if (phong[SHININESS] >= 0)
		m->shininess = phong[SHININESS];
	if (color[R] >= 0)
		m->color[R] = color[R];
	if (color[G] >= 0)
		m->color[G] = color[G];
	if (color[B] >= 0)
		m->color[B] = color[B];
	if (color[W] >= 0)
		m->color[W] = color[W];
}

// #include "../../tests/tester.h"
// Test(test, set_material) {
// 	t_sphere s = create_sphere();
//
// 	set_material((t_tuple){0.1, 0.2, 0.3, 0.4}, (t_tuple){0.5, 0.6, 0.7, 0.8}, &s.material);
// 	cr_expect_eq(TRUE, floats_eq(s.material.ambient, 0.1));
// 	cr_expect_eq(TRUE, floats_eq(s.material.diffuse, 0.2));
// 	cr_expect_eq(TRUE, floats_eq(s.material.specular, 0.3));
// 	cr_expect_eq(TRUE, floats_eq(s.material.shininess, 0.4));
//
// 	cr_expect_eq(TRUE, floats_eq(s.material.color[R], 0.5));
// 	cr_expect_eq(TRUE, floats_eq(s.material.color[G], 0.6));
// 	cr_expect_eq(TRUE, floats_eq(s.material.color[B], 0.7));
// 	cr_expect_eq(TRUE, floats_eq(s.material.color[W], 0.8));
// }
//
// Test(test, set_material_default_untouched) {
// 	t_sphere s = create_sphere();
//
// 	set_material((t_tuple){-1, -2, -3, 0.4}, (t_tuple){-0.5, -0.6, 0.7, COLOR}, &s.material);
// 	printf("ambient: %f\n", s.material.ambient);
// 	printf("diffuse: %f\n", s.material.diffuse);
// 	printf("specular: %f\n", s.material.specular);
// 	printf("shininess: %f\n", s.material.shininess);
// 	print_tuple(s.material.color);
// }
