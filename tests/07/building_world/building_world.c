#include "minirt.h"
#include "tester.h"

// // Scenario : Creating a world
// #define scenario1 CYAN                                               \
// "\nGiven w ← create_world()\n"                                              \
// "Then w contains no objects\n"                                       \
// "And w has no light source"RESET
//
// Test(building_world, create_world, .description = scenario1) {
// 	const t_world w = create_world();
// 	cr_expect_eq(w.objs, NULL);
// 	cr_expect_eq(w.light, NULL);
// }

// Scenario : The default world
#define scenario2 CYAN \
"\nGiven light ← point_light(point(-10, 10, -10), color(1, 1, 1))\n" \
"And s1 ← create_sphere() with:\n"                                   \
"material.color == (0.8, 1.0, 0.6)\n"                                \
"material.diffuse == 0.7\n"                                          \
"material.specular == 0.2\n"                                         \
"And s2 ← sphere() with:\n"											 \
"set_transform(s, scaling(0.5, 0.5, 0.5)) \n"                        \
"When w ← default_world()\n"                                         \
"Then w.light = light\n"                                         	 \
"And w contains s1\n"                                         		 \
"And w contains s2"RESET

Test(building_world, the_default_world, .description = scenario2) {
	const t_point_light expected_light = {
		.position = {-10, 10, -10, POINT},
		.intensity = {1, 1, 1, COLOR}
	};
	t_material expected = create_material();
	expected.color[R] = 0.8;
	expected.color[G] = 1.0;
	expected.color[B] = 0.6;
	t_world world = default_world();

	const t_matrix scaling_matrix = create_scaling_matrix(0.5, 0.5, 0.5);
	const t_matrix inverse_scaling_matrix = invert_matrix(scaling_matrix);
	printf("light position:\n");
	printf("expected:\n");
	print_tuple(expected_light.position);
	printf("actual:\n");
	print_tuple(world.light->position);
	cr_expect_tuples_eq(world.light->position, expected_light.position);
	printf("light intensity:\n");
	printf("expected:\n");
	print_tuple(expected_light.intensity);
	printf("actual:\n");
	print_tuple(world.light->intensity);
	cr_expect_tuples_eq(world.light->intensity, expected_light.intensity);
	printf("default material diffuse reflection:\n");
	printf("expected:\n");
	printf("%f\n", 0.7);
	printf("actual:\n");
	printf("%lf\n", world.objs[0].material.diffuse);
	cr_expect_eq(doubles_eq(world.objs[0].material.diffuse, 0.7), TRUE);
	printf("default material specular reflection:\n");
	printf("expected:\n");
	printf("%f\n", 0.2);
	printf("actual:\n");
	printf("%lf\n", world.objs[0].material.specular);
	cr_expect_eq(doubles_eq(world.objs[0].material.specular, 0.2), TRUE);
	printf("default material color:\n");
	printf("expected:\n");
	printf("%lf\n", expected.color);
	printf("actual:\n");
	printf("%lf\n", world.objs[0].material.color);
	cr_expect_tuples_eq(world.objs[0].material.color, expected.color);
	printf("scaling matrix of the second sphere:\n");
	printf("expected:\n");
	print_4x4matrix(scaling_matrix);
	printf("actual:\n");
	print_4x4matrix(world.objs[1]._t);
	cr_expect_matrices_eq(scaling_matrix, world.objs[1]._t);
	printf("inverse of the scaling matrix of the second sphere:\n");
	printf("expected:\n");
	print_4x4matrix(inverse_scaling_matrix);
	printf("actual:\n");
	print_4x4matrix(world.objs[1].inverse_t);
	cr_expect_matrices_eq(inverse_scaling_matrix, world.objs[1].inverse_t);
}

// // Scenario : Precomputing the state of an intersection
// #define scenario4 CYAN\
// "\nGiven r ← ray(point(0, 0, -5), vector(0, 0, 1))\n"                \
// "And shape ← create_sphere()\n"                						 \
// "And i ← intersection(4, shape)\n"                					 \
// "When prep_comps ← prepare_computations(i, r)\n"                	 \
// "Then prep_comps.t = i.t\n"                						 	 \
// "And prep_comps.object = i.object\n"                				 \
// "And prep_comps.point = point(0, 0, -1)\n"                			 \
// "And prep_comps.eyev = vector(0, 0, -1)\n"                			 \
// "And prep_comps.normalv = vector(0, 0, -1)"RESET
// Test(building_world, precomputing_the_state_of_an_intersection, .description = scenario4) {
// 	t_ray 					r = create_ray(
// 			(t_tuple){0, 0, -5, POINT},
// 			(t_tuple){0, 0, 1, VECTOR}
// 	);
// 	t_sphere				s = create_sphere();
// 	const void 				*s_ptr = &s;
// 	const t_node			*i = intersection(4, &s_ptr);
// 	t_prep_comps			prep_comps = prepare_computations(i, r);
//
// 	cr_expect_eq(doubles_eq(prep_comps.t, i->t), TRUE);
// 	cr_expect_eq(prep_comps.object, i->object); // must be the address of the same sphere
// 	cr_expect_tuples_eq(prep_comps.point, (t_tuple){0, 0, -1, POINT});
// 	cr_expect_tuples_eq(prep_comps.eyev, (t_tuple){0, 0, -1, VECTOR});
// 	cr_expect_tuples_eq(prep_comps.normalv, (t_tuple){0, 0, -1, VECTOR});
// }
//
// // Scenario : The hit, when an intersection occurs on the outside
// #define scenario5 CYAN\
// "\nGiven r ← ray(point(0, 0, -5), vector(0, 0, 1))\n"                \
// "And shape ← create_sphere()\n"                						 \
// "And i ← intersection(4, shape)\n"                					 \
// "When prep_comps ← prepare_computations(i, r)\n"                			 \
// "Then prep_comps.inside = false"RESET
// Test(building_world, hit_when_intersection_is_outside, .description = scenario5) {
// 	t_ray r = create_ray((t_tuple){0, 0, -5, POINT}, (t_tuple){VECTOR});
// 	const t_sphere s = create_sphere();
// 	const void *s_ptr = &s;
// 	const t_node *i = intersection(4, &s_ptr);
// 	const t_prep_comps prep_comps = prepare_computations(i, r);
//
// 	cr_expect_eq(prep_comps.inside, FALSE);
// }
//
// // Scenario : The hit, when an intersection occurs on the inside
// #define scenario6 CYAN\
// "And shape ← create_sphere()\n"                  					 \
// "\nGiven r ← ray(point(0, 0, 0), vector(0, 0, 1))\n"                 \
// "And i ← intersection(1, shape)\n"                  				 \
// "When prep_comps ← prepare_computations(i, r)\n"                  	 \
// "Then prep_comps.point = point(0, 0, 1)\n"                  		 \
// "And prep_comps.eyev = vector(0, 0, -1)\n"                  		 \
// "And prep_comps.inside = true\n"                  					 \
// "// normal would have been (0, 0, 1), but is inverted!\n"            \
// "And prep_comps.normalv = vector(0, 0, -1)"RESET
// Test(building_world, hit_when_intersection_is_inside, .description = scenario6) {
// 	t_sphere s;
// 	const void *s_ptr = &s;
// 	t_ray r;
// 	t_node *i;
// 	t_prep_comps prep_comps;
//
//
// 	s = create_sphere();
// 	r = create_ray((t_tuple){0, 0, 0, POINT}, (t_tuple){0, 0, 1, VECTOR});
// 	i = intersection(1, &s_ptr);
// 	prep_comps = prepare_computations(i, r);
// 	cr_expect_tuples_eq(prep_comps.point, (t_tuple){0, 0, 1, POINT});
// 	cr_expect_tuples_eq(prep_comps.eyev, (t_tuple){0, 0, -1, VECTOR});
// 	cr_expect_eq(prep_comps.inside, TRUE);
// 	cr_expect_tuples_eq(prep_comps.normalv, (t_tuple){0, 0, -1, VECTOR});
// }
//
// // Scenario : Shading an intersection
// #define scenario7 CYAN \
// "\nGiven w ← default_world()\n"                                        \
// "And r ← ray(point(0, 0, -5), vector(0, 0, 1))\n"                      \
// "And shape ← the first object in w\n"								   \
// "And i ← intersection(4, shape)\n"    								   \
// "When prep_comps ← prepare_computations(i, r)\n"                       \
// "And c ← shade_hit(w, prep_comps)\n"                                   \
// "Then c = color(0.38066, 0.47583, 0.2855)"RESET
// Test(building_world, shading_intersection, .description = scenario7) {
// 	t_world w;
// 	t_ray r;
// 	t_sphere s;
// 	const void *s_ptr = &s;
// 	t_node *i;
// 	t_tuple color;
// 	t_prep_comps prep_comps;
// 	const t_tuple expected_color = {0.38066, 0.47583, 0.2855, COLOR};
//
// 	w = default_world();
// 	r = create_ray((t_tuple){0, 0, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
// 	s = *(t_sphere *)w.objs;
// 	i = intersection(4, &s_ptr);
// 	prep_comps = prepare_computations(i, r);
//
// 	shade_hit(&w, &prep_comps, color);
// 	cr_expect_tuples_eq(color, expected_color);
// }
//
// // Scenario : Shading an intersection from the inside
// #define scenario8 CYAN\
// "\nGiven w ← default_world()\n"                                       \
// "And w.light ← point_light(point(0, 0.25, 0), color(1, 1, 1))\n"      \
// "And r ← ray(point(0, 0, 0), vector(0, 0, 1))\n"                      \
// "And shape ← the second object in w\n"                                \
// "And i ← intersection(0.5, shape)\n"                                  \
// "When prep_comps ← prepare_computations(i, r)\n"                      \
// "And c ← shade_hit(w, prep_comps)\n"                                  \
// "Then c = color(0.90498, 0.90498, 0.90498)"RESET
// Test(building_world, shading_intersection_from_inside, .description = scenario8) {
// 	t_world w = default_world();
// 	w.light = &(t_point_light){
// 		.position = {0, 0.25, 0, POINT},
// 		.intensity = {1, 1, 1, COLOR},
// 	};
// 	t_ray 			r = create_ray((t_tuple){0, 0, 0, POINT}, (t_tuple){0, 0, 1, VECTOR});
// 	t_sphere 		*s = &w.objs[1];
// 	const void 		**shape = &s;
// 	t_node	 		*i = intersection(0.5, shape);
// 	t_prep_comps 	prep_comps = prepare_computations(i, r);
// 	t_tuple 		color;
// 	shade_hit(&w, &prep_comps, color);
// 	print_tuple(color);
// 	cr_expect_tuples_eq(color, (t_tuple){0.90498, 0.90498, 0.90498, COLOR});
// }
//
// // Scenario : The color when a ray misses
// #define scenario9 CYAN\
// "\nGiven w ← default_world()\n"                                       \
// "And r ← ray(point(0, 0, -5), vector(0, 1, 0))\n"                     \
// "When c ← color_at(w, r)\n"                                       	  \
// "Then c = color(0, 0, 0)"RESET
// Test(building_world, the_color_when_a_ray_misses, .description = scenario9) {
// 	t_world w = default_world();
// 	t_ray 	r = create_ray((t_tuple){0, 0, -5, POINT}, (t_tuple){0, 1, 0, VECTOR});
// 	t_tuple color;
//
// 	color_at(&w, &r, color);
// 	cr_expect_tuples_eq(color, (t_tuple){0, 0, 0, COLOR});
// }
//
// // Scenario : The color when a ray hits
// #define scenario10 CYAN\
// "\nGiven w ← default_world()\n"                                       \
// "And r ← ray(point(0, 0, -5), vector(0, 0, 1))\n"                     \
// "When c ← color_at(w, r)\n"                                       	  \
// "Then c = color(0.38066, 0.47583, 0.2855"RESET
// Test(building_world, the_color_when_a_ray_hits, .description = scenario10) {
// 	t_world w = default_world();
// 	t_ray	r = create_ray((t_tuple){0, 0, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
// 	t_tuple color;
//
// 	color_at(&w, &r, color);
// 	cr_expect_tuples_eq(color, (t_tuple){0.38066, 0.47583, 0.2855, COLOR});
// }
//
// // Scenario : The color with an intersection behind the ray
// #define scenario11 CYAN\
// "\nGiven w ← default_world()\n"                                      \
// "And outer ← the first object in w\n"                                \
// "And outer.material.ambient ← 1\n"                                   \
// "And inner ← the second object in w\n"                               \
// "And inner.material.ambient ← 1\n"                                   \
// "And r ← ray(point(0, 0, 0.75), vector(0, 0, -1))\n"                 \
// "When c ← color_at(w, r)\n"                                          \
// "Then c = inner.material.color"RESET
// Test(building_world, the_color_with_intersection_behind_ray, .description = scenario11) {
// 	t_world w = default_world();
// 	t_sphere *outer = &w.objs[0];
// 	t_sphere *inner = &w.objs[1];
// 	outer->material.ambient = 1;
// 	inner->material.ambient = 1;
// 	t_ray	r = create_ray((t_tuple){0, 0, 0.75, POINT}, (t_tuple){0, 0, -1, VECTOR});
// 	t_tuple color;
//
// 	color_at(&w, &r, color);
// 	cr_expect_tuples_eq(color, inner->material.color);
// }
