#include "minirt.h"

#define wall_z 3
#define wall_size 50.0
#define canvas_pixels 1000

static inline void create_ppm_file(t_constr ppm_string, t_constr filename) {
    int fd = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    write(fd, ppm_string, ft_strlen(ppm_string));
    close(fd);
}

void quick_render(t_world *w, const t_tuple from) {

    t_camera camera = create_camera(100, 100, M_PI / 4);
    t_tuple to = (t_tuple){0, 0, 0, POINT};
    t_tuple up = (t_tuple){0, 1, 0, VECTOR};
    const t_tuple forward = subtract_tuples(to, from);

    const t_tuple normalized_forward = normalize(forward);
    camera.transform = view_transform(from, normalized_forward, up);

    t_canvas c = render(camera, *w);
    char *str = canvas_to_ppm(&c);
    create_ppm_file(str, "main.ppm");
    destroy_canvas(&c);
    free(str);
    free(w->objs);
}

static void normalize_rgb(t_tuple raw_rgb);
static t_tuple get_ray_direction(const t_tuple position, const t_tuple ray_origin);
static void paint_a_pixel(t_canvas *c, int y, int x);
static void randomize_color(t_tuple color);
static void ray_casting(const double half, const double pixel_size);

t_canvas c;
t_sphere s;
const t_tuple ray_origin = {0, 0, -10.0, POINT};

int main() {
    const double half = wall_size / 2;
    const double pixel_size = wall_size / canvas_pixels;

    c = create_canvas(canvas_pixels, canvas_pixels);
    s = create_sphere();
    set_transform(&s, create_scaling_matrix(9.980, 9.980, 9.980));
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
    t_ray r;
    t_intersections xs;
	t_sphere s;

	s = create_sphere();
    y = -1;
    while (++y < c.height) {
        x = -1;
        world_y = half - pixel_size * y;
        while (++x < c.width) {
            world_x = -half + pixel_size * x;
            direction = get_ray_direction((t_tuple){world_x, world_y, wall_z, POINT}, ray_origin);
            r = create_ray(ray_origin, direction);
            xs = intersect_sphere(&s, r);
            if (_hit(xs).object != NULL)
                paint_a_pixel(&c, y, x);
			ft_lstfree(&xs.head);
        }
    }
}

static t_tuple get_ray_direction(const t_tuple position, const t_tuple ray_origin) {
    t_tuple sphere_to_ray;
	t_tuple direction;

    sphere_to_ray = subtract_tuples(position, ray_origin);
    direction = normalize(sphere_to_ray);
	return (direction);
}

static void randomize_color(t_tuple color) {
    color.x = rand() % 255;
    color.y = rand() % 255;
    color.z = rand() % 255;
	color.w = COLOR;
    normalize_rgb(color);
}

static void paint_a_pixel(t_canvas *c, int y, int x) {
    t_tuple color = {1, 0, 0, COLOR};

    randomize_color(color);
    write_pixel(c, y, x, color);
}

static void normalize_rgb(t_tuple raw_rgb) {
    raw_rgb.x = raw_rgb.x / 255;
    raw_rgb.y = raw_rgb.y / 255;
    raw_rgb.z = raw_rgb.z / 255;
}
