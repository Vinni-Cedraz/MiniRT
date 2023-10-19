// canvas ← canvas(canvas_pixels, canvas_pixels)
// color ← color(1, 0, 0) # red
// shape ← sphere()
// # for each row of pixels in the canvas
// for y ← 0 to canvas_pixels - 1
// »
// »
// # compute the world y coordinate (top = +half, bottom = -half)
// world_y ← half - pixel_size * y
// # for each pixel in the row
// for x ← 0 to canvas_pixels - 1
// # compute the world x coordinate (left = -half, right = half)
// world_x ← -half + pixel_size * x# describe the point on the wall that the ray will
// target position ← point(world_x, world_y, wall_z) r ← ray(ray_origin,
// normalize(position - ray_origin)) xs ← intersect(shape, r) if hit(xs) is defined
// write_pixel(canvas, x, y, color)
// end if
// end for
// end for

#include "tester.h"

static void normalize_rgb(t_tuple raw_rgb) {
    raw_rgb[X] = raw_rgb[X] / 255;
    raw_rgb[Y] = raw_rgb[Y] / 255;
    raw_rgb[Z] = raw_rgb[Z] / 255;
}


Test(putting_it_together, drawing_a_circle) {
    int y;
    int x;
    t_tuple color = {161, 201, 247, COLOR};
    t_canvas c = create_canvas(10, 10);
	int canvas_size = c.width * c.height;
	int wall_z = 10;
    t_sphere ball = create_sphere();
    normalize_rgb(color);
	float pixel_size = 7.0 / canvas_size;
	const t_tuple ray_origin = {0, 0, -5, POINT};

    // do what the comment at the beginning of the file says:
    // for each row of pixels in the canvas
    for (y = 0; y < c.height; y++) {
        // compute the world y coordinate (top = +half, bottom = -half)
        double world_y = c.height / 2.0 - pixel_size * y;
        // for each pixel in the row
        for (x = 0; x < c.width; x++) {
            // compute the world x coordinate (left = -half, right = half)
            double world_x = -1 * (c.width / 2.0 + pixel_size * x);
            // describe the point on the wall that the ray will target
            t_tuple position = {world_x, world_y, wall_z, POINT};
			t_tuple sphere_to_ray;
			t_tuple normalized_vector;
			subtract_tuples(&position, &ray_origin, &sphere_to_ray);
			normalize(&sphere_to_ray, &normalized_vector);
			print_tuple(normalized_vector);
            t_ray r = create_ray((t_tuple){0, 0, -5, POINT}, normalized_vector);
            t_intersection xs = create_intersection(ball, r);
        }
    }

    t_constr ppm_string = canvas_to_ppm(&c);
    create_ppm_file(ppm_string);
    destroy_canvas(&c);
}
