#include "include/minirt.h"

int main ()
{
 	t_world w = default_world();
 	t_ray r = create_ray((t_tuple){0, 0, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
 	t_intersections xs = intersect_world_with_ray(&w, &r);

	printf("xs.count -> %d\n", xs.count);
	printf("first > %f\n", xs.head->t);
	printf("second > %f\n", xs.head->next->t);
	printf("third > %f\n", xs.head->next->next->t);
	printf("fourth > %f\n", xs.head->next->next->next->t);