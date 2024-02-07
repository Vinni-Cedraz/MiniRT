#include "tester.h"

#define wall_z 1000
#define wall_size 2000.0
#define canvas_size 1000

static void normalize_rgb(t_tuple raw_rgb);
static void get_ray_direction(const t_tuple position, const t_tuple ray_origin, t_tuple direction);
static void paint_a_pixel(t_canvas *c, int y, int x, t_lighting *lighting, t_ray *r);
static void randomize_color(t_tuple color);
static void ray_casting(const double half, const double pixel_size, t_ray r, t_intersection xs);

t_canvas c;
t_sphere s;
const t_tuple ray_origin = {0, 0, -15, POINT};
t_sphere s;

Test(putting_it_together, drawing_a_circle) {
    t_ray r;
    t_intersection xs;
    const double half = wall_size / 2;
    const double pixel_size = wall_size / canvas_size;
 	s = create_sphere();
    c = create_canvas(canvas_size, canvas_size);
#define scale 10
    set_transform(&s, create_scaling_matrix(scale, scale, scale));
    ray_casting(half, pixel_size, r, xs);

    t_constr *str = canvas_to_ppm(&c);
    create_ppm_file(str, "drawing_a_circle.ppm");
    destroy_canvas(&c);
}

static void ray_casting(const double half, const double pixel_size, t_ray r, t_intersection xs) {
    int x;
    int y;
    int world_x;
    int world_y;
    t_tuple direction;
	t_node *hit;
	t_lighting ligthing_obj;

    y = -1;
    while (++y < c.height) {
        x = -1;
        world_y = half - pixel_size * y;
        while (++x < c.width) {
            world_x = -half + pixel_size * x;
            get_ray_direction((t_tuple){world_x, world_y, wall_z, POINT}, ray_origin, direction);
            r = create_ray(ray_origin, direction);
            xs = create_intersection(&s, r);
        	hit = get_hit(xs);
			if (hit)
			{
				get_position(r, hit->t, ligthing_obj.position);
				sphere_normal_at(hit->object, ligthing_obj.position, ligthing_obj.normal_vec);
                paint_a_pixel(&c, y, x, &ligthing_obj, &r);
			}
        }
    }
}

static void get_ray_direction(const t_tuple position, const t_tuple ray_origin, t_tuple direction) {
    t_tuple sphere_to_ray;

    create_vector(sphere_to_ray);
    subtract_tuples(position, ray_origin, sphere_to_ray);
    normalize(sphere_to_ray, direction);
}

static void set_material_color(t_material *m, t_tuple color) {
	m->color[R] = color[R];
	m->color[G] = color[G];
	m->color[B] = color[B];
}

static void paint_a_pixel(t_canvas *c, int y, int x, t_lighting *lighting, t_ray *r) {
    t_tuple color;

    lighting->material = s.material;
	set_material_color(&lighting->material, (t_tuple){1, 0.2, 1});
    negate_tuple(r->direction, lighting->eye_vec);
    lighting->light = (t_point_light){
			.position = {-10, 10, -10, POINT},
			.intensity = {1, 1, 1, COLOR},
	};

    calculate_lighting(lighting, color);
    write_pixel(c, y, x, color);
}

static void normalize_rgb(t_tuple raw_rgb) {
    raw_rgb[X] = raw_rgb[X] / 255;
    raw_rgb[Y] = raw_rgb[Y] / 255;
    raw_rgb[Z] = raw_rgb[Z] / 255;
}
