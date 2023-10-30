#include "minirt.h"
#include "tester.h"

// Scenario : Creating a world
#define scenario1 CYAN                                               \
"\nGiven w ← create_world()\n"                                              \
"Then w contains no objects\n"                                       \
"And w has no light source"RESET

Test(building_world, create_world, .description = scenario1) {
	const t_world w = create_world();
	cr_expect_eq(w.objs, NULL);
	cr_expect_eq(w.light, NULL);
}

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
	t_material m = create_material();
	m.color[R] = 0.8;
	m.color[G] = 1.0;
	m.color[B] = 0.6;
	t_world world = default_world();

	cr_expect_tuples_eq(world.light->position, expected_light.position);
	cr_expect_tuples_eq(world.light->intensity, expected_light.intensity);
	cr_expect_eq(floats_eq(world.objs[1].radius, 0.5), TRUE);
	printf("RADIUS: %f\n", world.objs[1].radius);
	printf("sphere1: \n");
	print_sphere(&world.objs[0]);
	printf("sphere2: \n");
	print_sphere(&world.objs[1]);
	// cr_expect_eq(floats_eq(world.objs[0].radius, 1.0), TRUE);
	// cr_expect_eq(floats_eq(world.objs[0].material.diffuse, 0.7), TRUE);
	// cr_expect_eq(floats_eq(world.objs[0].material.specular, 0.2), TRUE);
	// cr_expect_tuples_eq(world.objs[0].material.color, m.color);
}

// Scenario : Intersect a world with a ray
#define scenario3 CYAN \
"\nGiven w ← default_world()\n"                                      \
"And r ← ray(point(0, 0, -5), vector(0, 0, 1))\n"                    \
"When xs ← intersect_world(w, r)\n"                                  \
"Then xs.count = 4\n"                                        		 \
"And xs[0].t = 4\n"                                      			 \
"And xs[1].t = 4.5\n"                                      			 \
"And xs[2].t = 5.5\n"                                      			 \
"And xs[3].t = 6"RESET

// Test(building_world, intersect_world_with_ray, .description = scenario3) {
// }

// Scenario : Precomputing the state of an intersection
#define scenario4 CYAN\
"\nGiven r ← ray(point(0, 0, -5), vector(0, 0, 1))\n"                \
"And shape ← create_sphere()\n"                							 \
"And i ← intersection(4, shape)\n"                					 \
"When comps ← prepare_computations(i, r)\n"                			 \
"Then comps.t = i.t\n"                								 \
"And comps.object = i.object\n"                						 \
"And comps.point = point(0, 0, -1)\n"                				 \
"And comps.eyev = vector(0, 0, -1)\n"                				 \
"And comps.normalv = vector(0, 0, -1)"RESET

// Scenario : The hit, when an intersection occurs on the outside
#define scenario5 CYAN\
"\nGiven r ← ray(point(0, 0, -5), vector(0, 0, 1))\n"                \
"And shape ← create_sphere()\n"                							 \
"And i ← intersection(4, shape)\n"                					 \
"When comps ← prepare_computations(i, r)\n"                			 \
"Then comps.inside = false"RESET

// Scenario : The hit, when an intersection occurs on the inside
#define scenario6 CYAN\
"And shape ← create_sphere()\n"                  							 \
"\nGiven r ← ray(point(0, 0, 0), vector(0, 0, 1))\n"                 \
"And i ← intersection(1, shape)\n"                  				 \
"When comps ← prepare_computations(i, r)\n"                  		 \
"Then comps.point = point(0, 0, 1)\n"                  				 \
"And comps.eyev = vector(0, 0, -1)\n"                  				 \
"And comps.inside = true\n"                  						 \
"// normal would have been (0, 0, 1), but is inverted!\n"            \
"And comps.normalv = vector(0, 0, -1)"RESET

// Scenario : Shading an intersection
#define scenario7 CYAN\
"\nGiven w ← default_world()\n                                        \
"And r ← ray(point(0, 0, -5), vector(0, 0, 1))\n                      \
"And shape ← the first object in wAnd i ← intersection(4, shape)\n    \
"When comps ← prepare_computations(i, r)\n                            \
"And c ← shade_hit(w, comps)\n                                        \
"Then c = color(0.38066, 0.47583, 0.2855)"RESET

// Scenario : Shading an intersection from the inside
#define scenario8 CYAN\
"\nGiven w ← default_world()\n"                                       \
"And w.light ← point_light(point(0, 0.25, 0), color(1, 1, 1))\n"      \
"And r ← ray(point(0, 0, 0), vector(0, 0, 1))\n"                      \
"And shape ← the second object in w\n"                                \
"And i ← intersection(0.5, shape)\n"                                  \
"When comps ← prepare_computations(i, r)\n"                           \
"And c ← shade_hit(w, comps)\n"                                       \
"Then c = color(0.90498, 0.90498, 0.90498)"RESET

// Scenario : The color when a ray misses
#define scenario9 CYAN\
"\nGiven w ← default_world()\n"                                       \
"And r ← ray(point(0, 0, -5), vector(0, 1, 0))\n"                     \
"When c ← color_at(w, r)\n"                                       	  \
"Then c = color(0, 0, 0)"RESET

// Scenario : The color when a ray hits
#define scenario10 CYAN\
"\nGiven w ← default_world()\n"                                       \
"And r ← ray(point(0, 0, -5), vector(0, 0, 1))\n"                     \
"When c ← color_at(w, r)\n"                                       	  \
"Then c = color(0.38066, 0.47583, 0.2855"RESET

// Scenario : The color with an intersection behind the ray
#define scenario11 CYAN\
"\nGiven w ← default_world()\n"                                      \
"And outer ← the first object in w\n"                                \
"And outer.material.ambient ← 1\n"                                   \
"And inner ← the second object in w\n"                               \
"And inner.material.ambient ← 1\n"                                   \
"And r ← ray(point(0, 0, 0.75), vector(0, 0, -1))\n"                 \
"When c ← color_at(w, r)\n"                                          \
"Then c = inner.material.color"RESET
