#include "../../tests/tester.h"

int main()
{
	const t_camera 	c = create_camera(201, 101, M_PI/2);
	const t_ray 	r = ray_for_pixel(c, 100, 50);
	print_tuple(r.origin);
	print_tuple(r.direction);
}
