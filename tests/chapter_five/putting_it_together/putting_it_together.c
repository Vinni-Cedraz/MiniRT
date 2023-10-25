#include "minirt.h"
#include "tester.h"

static void normalize_rgb(t_tuple raw_rgb) {
    raw_rgb[X] = raw_rgb[X] / 255;
    raw_rgb[Y] = raw_rgb[Y] / 255;
    raw_rgb[Z] = raw_rgb[Z] / 255;
}

static void get_ray_direction(const t_tuple position, const t_tuple ray_origin,
                              t_tuple direction);

Test(putting_it_together, drawing_a_circle) {
    t_canvas c;
    t_ray r;
    t_intersection xs;
    t_sphere s;
    int x;
    int y;
    int world_x;
    int world_y;
    t_tuple direction = {15, 15, 15, VECTOR};
    const float wall_z = 10;
    const float wall_size = 7;
    const float pixel_size = wall_size / 100;
    const float half = wall_size / 2;
    const t_tuple ray_origin = {0, 0, -5.0, POINT};
	const t_tuple color = {1, 0, 0, COLOR};

    x = -1;
    y = -1;
    c = create_canvas(10, 10);
    s = create_sphere();
    // set_transform(&s, create_scaling_matrix(1, 1, 1));
    // write_pixel(&c, c.height/2, c.width/2, (t_tuple){1, 0, 0, COLOR});
    while (++y <= c.height - 1) {
        x = -1;
        world_y = half - (pixel_size * y);
        while (++x <= c.width - 1) {
            world_x = -half + (pixel_size * x);
            get_ray_direction((t_tuple){world_x, world_y, wall_z, POINT}, ray_origin, direction);
			r = create_ray(ray_origin, direction);
			xs = create_intersection(s, r);
			if (get_hit(xs) != NULL) 
				write_pixel(&c, y, x, color);
        }
    }
    t_constr *str = canvas_to_ppm(&c);
    create_ppm_file(str);
    destroy_canvas(&c);
}

static void get_ray_direction(const t_tuple position, const t_tuple ray_origin, t_tuple direction) {
    t_tuple sphere_to_ray;
    subtract_tuples(position, ray_origin, sphere_to_ray);
    normalize(sphere_to_ray, direction);
}
