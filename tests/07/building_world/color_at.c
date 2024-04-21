#include "../../tester.h"

// Scenario : The color when a ray misses
#define scenario1 CYAN\
"\nGiven w ← default_world()\n"                                       \
"And r ← ray(point(0, 0, -5), vector(0, 1, 0))\n"                     \
"When c ← color_at(w, r)\n"                                       	  \
"Then c = color(0, 0, 0)"RESET
Test(color_at, the_color_when_a_ray_misses, .description = scenario1) {
	t_world w = default_world();
	t_ray 	r = create_ray((t_tuple){0, 0, -5, POINT}, (t_tuple){0, 1, 0, VECTOR});
	t_tuple color;

	color = color_at(&w, &r);
	cr_expect_tuples_eq(color, (t_tuple){0, 0, 0, COLOR});
}

// Scenario : The color when a ray hits
#define scenario2 CYAN\
"\nGiven w ← default_world()\n"                                       \
"And r ← ray(point(0, 0, -5), vector(0, 0, 1))\n"                     \
"When c ← color_at(w, r)\n"                                       	  \
"Then c = color(0.38066, 0.47583, 0.2855"RESET
Test(color_at, the_color_when_a_ray_hits, .description = scenario2) {
	t_world w = default_world();
	t_ray	r = create_ray((t_tuple){0, 0, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	t_tuple color;

	color = color_at(&w, &r);
	cr_expect_tuples_eq(color, (t_tuple){0.38066, 0.47583, 0.2855, COLOR});
}

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
Test(color_at, the_color_with_intersection_behind_ray, .description = scenario11) {
	t_world w = default_world();
	t_shape *outer = &w.shapes[0];
	t_shape *inner = &w.shapes[1];
	outer->material.ambient = 1;
	inner->material.ambient = 1;
	t_ray	r = create_ray((t_tuple){0, 0, 0.75, POINT}, (t_tuple){0, 0, -1, VECTOR});
	t_tuple color;

	color = color_at(&w, &r);
	cr_expect_tuples_eq(color, inner->material.color);
}
