#include "../../tester.h"

#define wall_z 1000
#define wall_size 2000.0
#define canvas_size 1000

static void normalize_rgb(t_tuple raw_rgb);
static t_tuple get_ray_direction(const t_tuple position, const t_tuple ray_origin);
static void paint_a_pixel(t_canvas *c, int y, int x, t_lighting *lighting, t_ray *r);
static void randomize_color(t_tuple color);
static void ray_casting(const double half, const double pixel_size);

t_canvas c;
t_sphere s;
const t_tuple ray_origin = {0, 0, -15, POINT};
t_sphere s;

Test(putting_it_together, drawing_a_circle) {
    const double half = wall_size / 2;
    const double pixel_size = wall_size / canvas_size;
 	s = create_sphere();
    c = create_canvas(canvas_size, canvas_size);
#define scale 10
    set_transform(&s, create_scaling_matrix(scale, scale, scale));
    ray_casting(half, pixel_size);

    const char *str = canvas_to_ppm(&c);
    create_ppm_file(str, "drawing_a_circle.ppm");
    destroy_canvas(&c);
}

static void ray_casting(const double half, const double pixel_size) {
    int x;
    int y;
    int world_x;
    int world_y;
    t_tuple direction;
	t_node hit;
	t_lighting ligthing_obj;
    t_ray r;
    t_intersections xs;

    y = -1;
    while (++y < c.height) {
        x = -1;
        world_y = half - pixel_size * y;
        while (++x < c.width) {
            world_x = -half + pixel_size * x;
            direction = get_ray_direction((t_tuple){world_x, world_y, wall_z, POINT}, ray_origin);
            r = create_ray(ray_origin, direction);
            xs = intersect_sphere(&s, r);
        	hit = _hit(xs);
			if (hit.object)
			{
				ligthing_obj.position = _intersection_coordinates(r, hit.t);
				ligthing_obj.normal_vec = sphere_normal_at(hit.object, ligthing_obj.position);
                paint_a_pixel(&c, y, x, &ligthing_obj, &r);
			}
        }
    }
}

static t_tuple get_ray_direction(const t_tuple position, const t_tuple ray_origin) {
    t_tuple sphere_to_ray;

    sphere_to_ray = subtract_tuples(position, ray_origin);
    return(normalize(sphere_to_ray));
}

static void set_material_color(t_material *m, t_tuple color) {
	m->color.x = color.x;
	m->color.y = color.y;
	m->color.z = color.z;
}

static void paint_a_pixel(t_canvas *canvas, int y, int x, t_lighting *lighting, t_ray *r) {
    t_tuple color;

    lighting->material = s.material;
	set_material_color(&lighting->material, (t_tuple){1, 0.2, 1, COLOR});
    lighting->eye_vec = negate_tuple(r->direction);
    lighting->light = (t_point_light){
			.position = {-10, 10, -10, POINT},
			.intensity = {1, 1, 1, COLOR},
	};

    calculate_lighting(lighting, color);
    write_pixel(canvas, y, x, color);
}

static void normalize_rgb(t_tuple raw_rgb) {
    raw_rgb.x = raw_rgb.x / 255;
    raw_rgb.y = raw_rgb.y / 255;
    raw_rgb.z = raw_rgb.z / 255;
}
