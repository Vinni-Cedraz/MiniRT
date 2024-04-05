#include "minirt.h"

int main() {
	const t_ray r = create_ray((t_tuple){0, 0, -2, POINT}, (t_tuple){0, 0.240192, 0.970725, VECTOR});
	t_sphere s = create_sphere();
	const t_intersections i = intersect(&s, r);
	if (doubles_eq(i.this_obj_intersections[0].t, sqrt(3)) == FALSE)
		printf(RED"inter.this_obj_intersections->t %f\n", i.this_obj_intersections[0].t);
	if (doubles_eq(i.this_obj_intersections[1].t, sqrt(3)) == FALSE)
		printf(RED"inter.this_obj_intersections->next->t %f\n"RESET, i.this_obj_intersections[1].t);
}
