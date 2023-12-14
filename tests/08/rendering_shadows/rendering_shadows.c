#include "tester.h"

// I received an email from the Academy 4 days ago after enrolling, and I have been waiting to receive the English test since then. When should I expect to receive it?

// Scenario: shade_hit() is given an intersection in shadow
#define scenario1 CYAN \
"Given w ← world()\n"                                             \
"And w.light ← point_light(point(0, 0, -10), color(1, 1, 1))\n"   \
"And s1 ← sphere()\n"                                             \
"And s1 is added to w\n"                                          \
"And s2 ← sphere() with:\n"                                       \
"| transform | translation(0, 0, 10) |\n"                         \
"And s2 is added to w\n"                                          \
"And r ← ray(point(0, 0, 5), vector(0, 0, 1))\n"                  \
"And i ← intersection(4, s2)\n"                                   \
"When comps ← prepare_computations(i, r)\n"                       \
"And color ← shade_hit(w, comps)\n"                                   \
"Then color = color(0.1, 0.1, 0.1)"RESET

Test(rendering_shadows, shade_hit_receives_a_hit_in_shadow, .description = scenario1)
{
    t_world     	w;
    t_sphere		*s1 = malloc(sizeof(t_sphere));
    t_sphere		*s2 = malloc(sizeof(t_sphere));
    t_ray       	r;
    t_node			*head;
    t_prep_comps	comps;
    t_tuple			color;

    w = create_world();
    w.light = &(t_point_light){
		.position = {0, 0, -10, POINT},
		.intensity = {1, 1, 1, COLOR},
	};
    *s1 = create_sphere();
    *s2 = create_sphere();
    set_transform((t_shape *)s2, create_translation_matrix((t_tuple){0, 0, 10}));
    add_object(&w, (t_shape *)s1, 0);
    add_object(&w, (t_shape *)s2, 1);
    r = (t_ray){
		.origin = {0, 0, 5, POINT},
		.direction = {0, 0, 1, VECTOR}
	};
    head = intersection(4, (t_shape **)&s2);
    comps = prepare_computations(head, r);
    shade_hit(&w, &comps, color);
    cr_expect_tuples_eq(color, (t_tuple){0.1, 0.1, 0.1, COLOR});
}

// Scenario: The hit should offset the point
#define scenario2 CYAN \
"Given r ← ray(point(0, 0, -5), vector(0, 0, 1))\n"             \
"And shape ← sphere() with:\n"                                  \
"| transform | translation(0, 0, 1) |\n"                        \
"And i ← intersection(5, shape)\n"                              \
"When comps ← prepare_computations(i, r)\n"                     \
"Then comps.over_point.z < -EPSILON/2\n"                        \
"And comps.point.z > comps.over_point.z"RESET

Test(rendering_shadows, hit_should_offset_the_point, .description = scenario2) {
	t_prep_comps		comps;
	t_sphere			*s;
	t_node				*i;
	const t_ray			r = {
		.origin = {0, 0, -5, POINT},
		.direction = {0, 0, 1, VECTOR}
	};

	s = malloc(sizeof(t_sphere));
	*s = create_sphere();
	set_transform((t_shape *)s, create_translation_matrix((t_tuple){0, 0, 1, POINT}));
	i = intersection(5, (t_shape **)&s);
	comps = prepare_computations(i, r);

	cr_expect(comps.over_point[Z] < -EPSILON / 2);
	cr_expect(comps.point[Z] > comps.over_point[Z]);
}
