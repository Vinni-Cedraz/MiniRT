/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:12:46 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/31 16:14:34 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	is_not_default(double a);
static void		init_phong_pointers(double *phong_values[4], t_material *m);
static void		init_phong_values(double *phong_values[4], t_tuple new_phong);
static void		init_color_values(t_material *m, t_tuple new_color);

void	set_material(t_tuple new_phong, t_tuple new_color, t_material *m)
{
	double	*phong_values[4];

	init_phong_pointers(phong_values, m);
	init_phong_values(phong_values, new_phong);
	init_color_values(m, new_color);
}

static void	init_phong_pointers(double *phong_values[4], t_material *m)
{
	phong_values[0] = &m->ambient;
	phong_values[1] = &m->diffuse;
	phong_values[2] = &m->specular;
	phong_values[3] = &m->shininess;
}

static void	init_phong_values(double *phong_values[4], t_tuple new_phong)
{
	int	counter;

	counter = -1;
	while (++counter < 4)
	{
		if (is_not_default(new_phong[counter]))
			*phong_values[counter] = new_phong[counter];
	}
}

static void	init_color_values(t_material *m, t_tuple new_color)
{
	int	counter;

	counter = -1;
	while (++counter < 4)
	{
		if (is_not_default(new_color[counter]))
			m->color[counter] = new_color[counter];
	}
}

static t_bool	is_not_default(double a)
{
	if (a != DEFAULT)
		return (TRUE);
	return (FALSE);
}

// #include "../../tests/tester.h"
//
// Test(test, set_material)
// {
// 	t_sphere	s;
//
// 	s = create_sphere();
// 	set_material((t_tuple){0.1, 0.2, 0.3, 0.4}, (t_tuple){0.5, 0.6, 0.7, 0.8},
// 		&s.material);
//
// 	printf("ambient: %f\n", s.material.ambient);
// 	printf("diffuse: %f\n", s.material.diffuse);
// 	printf("specular: %f\n", s.material.specular);
// 	printf("shininess: %f\n", s.material.shininess);
// 	print_tuple(s.material.color);
//
// 	cr_expect_eq(TRUE, doubles_eq(s.material.ambient, 0.1));
// 	cr_expect_eq(TRUE, doubles_eq(s.material.diffuse, 0.2));
// 	cr_expect_eq(TRUE, doubles_eq(s.material.specular, 0.3));
// 	cr_expect_eq(TRUE, doubles_eq(s.material.shininess, 0.4));
// 	cr_expect_eq(TRUE, doubles_eq(s.material.color[R], 0.5));
// 	cr_expect_eq(TRUE, doubles_eq(s.material.color[G], 0.6));
// 	cr_expect_eq(TRUE, doubles_eq(s.material.color[B], 0.7));
// 	cr_expect_eq(TRUE, doubles_eq(s.material.color[W], 0.8));
// }
//
// Test(test, set_material_default_untouched)
// {
// 	t_sphere	s;
//
// 	s = create_sphere();
// 	set_material((t_tuple){DEFAULT, DEFAULT, DEFAULT, 0.4}, (t_tuple){DEFAULT,
// 		DEFAULT, 0.7, COLOR}, &s.material);
// 	printf("ambient: %f\n", s.material.ambient);
// 	printf("diffuse: %f\n", s.material.diffuse);
// 	printf("specular: %f\n", s.material.specular);
// 	printf("shininess: %f\n", s.material.shininess);
// 	print_tuple(s.material.color);
// }
