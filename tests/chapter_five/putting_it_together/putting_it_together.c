#include "minirt.h"
#include "tester.h"

static void normalize_rgb(t_tuple raw_rgb) {
    raw_rgb[X] = raw_rgb[X] / 255;
    raw_rgb[Y] = raw_rgb[Y] / 255;
    raw_rgb[Z] = raw_rgb[Z] / 255;
}


Test(putting_it_together, drawing_a_circle) {
	t_canvas c;
	t_ray r;
	t_intersection xs;
	t_sphere s;
	float wall_z = 10;
	int x;
	int y;
	int world_x;
	int world_y;
	t_tuple sphere_to_ray;
	t_tuple direction;


	x = -1;
	y = -1;
	c = create_canvas(1080, 1920);
	s = create_sphere();
	set_transform(&s, create_scaling_matrix(5, 5, 5));
	write_pixel(&c, c.height/2, c.width/2, (t_tuple){1, 0, 0, COLOR});
	while (++y <= c.height)
	{
		x = -1;
		while(++x <= c.width)
		{
			t_tuple position = {x, y, wall_z, POINT};
			subtract_tuples(position, r.origin, sphere_to_ray);
			normalize(sphere_to_ray, direction);
			r = create_ray((t_tuple){0, 0, -6, POINT}, direction);
			xs = create_intersection(s, r);
			if (get_hit(xs) != NULL) 
			{
				world_x = invert_axis(c.width, (c.width/2.0) + x);
				world_y = invert_axis(c.height, (c.height/2.0) + y);
				write_pixel(&c, world_y, world_x, (t_tuple){1, 0, 0, COLOR});
				world_x = invert_axis(c.width, (c.width/2.0) - x);
				world_y = invert_axis(c.height, (c.height/2.0) - y);
				write_pixel(&c, world_y, world_x, (t_tuple){1, 0, 0, COLOR});
				world_x = invert_axis(c.width, (c.width/2.0) - x);
				world_y = invert_axis(c.height, (c.height/2.0) + y);
				write_pixel(&c, world_y, world_x, (t_tuple){1, 0, 0, COLOR});
				world_x = invert_axis(c.width, (c.width/2.0) + x);
				world_y = invert_axis(c.height, (c.height/2.0) - y);
				write_pixel(&c, world_y, world_x, (t_tuple){1, 0, 0, COLOR});
			}
		}
	}
	t_constr *str = canvas_to_ppm(&c);
	create_ppm_file(str);
	destroy_canvas(&c);
}
