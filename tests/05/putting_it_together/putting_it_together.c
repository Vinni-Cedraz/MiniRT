#include "minirt.h"
#include "tester.h"

#define wall_z 7
#define wall_size 1000.0
#define canvas_pixels 1000

static void normalize_rgb(t_tuple raw_rgb);
static void get_ray_direction(const t_tuple position, const t_tuple ray_origin, t_tuple direction);
static void paint_a_pixel(t_canvas *c, int y, int x);
static void randomize_color(t_tuple color);
static void ray_casting(const float half, const float pixel_size, t_ray r, t_intersection xs);

t_canvas c;
t_sphere s;
const t_tuple ray_origin = {0, 0, -10.0, POINT};

Test(putting_it_together, drawing_a_circle) {
    t_ray r;
    t_intersection xs;
    const float half = wall_size / 2;
    const float pixel_size = wall_size / canvas_pixels;

    c = create_canvas(canvas_pixels, canvas_pixels);
    s = create_sphere();
    set_transform(&s, create_scaling_matrix(9.980, 9.980, 9.980));
    ray_casting(half, pixel_size, r, xs);
    t_constr *str = canvas_to_ppm(&c);
    create_ppm_file(str, "drawing_a_circle.ppm");
    destroy_canvas(&c);
}

static void ray_casting(const float half, const float pixel_size, t_ray r, t_intersection xs) {
    int x;
    int y;
    int world_x;
    int world_y;
    t_tuple direction;

    y = -1;
    while (++y < c.height) {
        x = -1;
        world_y = half - pixel_size * y;
        while (++x < c.width) {
            world_x = -half + pixel_size * x;
            get_ray_direction((t_tuple){world_x, world_y, wall_z, POINT}, ray_origin, direction);
            r = create_ray(ray_origin, direction);
            xs = create_intersection(&s, r);
            if (get_hit(xs) != NULL)
                paint_a_pixel(&c, y, x);
        }
    }
}

static void get_ray_direction(const t_tuple position, const t_tuple ray_origin, t_tuple direction) {
    t_tuple sphere_to_ray;

    create_vector(sphere_to_ray);
    subtract_tuples(position, ray_origin, sphere_to_ray);
    normalize(sphere_to_ray, direction);
}

static void randomize_color(t_tuple color) {
    color[X] = rand() % 255;
    color[Y] = rand() % 255;
    color[Z] = rand() % 255;
    normalize_rgb(color);
}

static void paint_a_pixel(t_canvas *c, int y, int x) {
    t_tuple color = {1, 0, 0, COLOR};
    randomize_color(color);
    write_pixel(c, y, x, color);
}

static void normalize_rgb(t_tuple raw_rgb) {
    raw_rgb[X] = raw_rgb[X] / 255;
    raw_rgb[Y] = raw_rgb[Y] / 255;
    raw_rgb[Z] = raw_rgb[Z] / 255;
}
